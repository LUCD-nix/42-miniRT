/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raymarch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:33:38 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/12 17:33:38 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rendering.h"

float	soft_shadow(t_point_light light, t_shapes *objs, t_vec3 point)
{
	t_soft_shadows	s;
	int				i;

	s.intensity = 1.0;
	s.walk = SHADOW_DIST_MIN;
	s.direction = norm3(diff3(light.position, point));
	i = -1;
	s.previous = 1e20;
	s.y = 0;
	while (++i < 256 && s.walk < SHADOW_DIST_MAX && s.intensity > SHADOW_I_MIN)
	{
		s.delta = scene(add3(point, fmult3(s.direction, s.walk)), objs).dist;
		if (s.delta < SURFACE_DIST)
			return (0.f);
		if (i != 0)
			s.y = s.delta * s.delta / (2.0f * s.previous);
		s.d = sqrtf(s.delta * s.delta - s.y * s.y);
		s.intensity = fminf(s.intensity,
				s.d / (light.radius * fmaxf(0.0f, s.walk - s.y)));
		s.previous = s.delta;
		s.walk += s.delta;
	}
	s.normal = dot3(s.direction, get_normal(point, objs));
	return (fminf(fmaxf(s.intensity, 0.f), 1.0f) * s.normal);
}
