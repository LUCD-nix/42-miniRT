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
	float	intensity;
	float	previous;
	float	walk;
	float	delta;
	float	y;
	float	d;
	t_vec3	direction;

	intensity = 1.0;
	walk = SHADOW_DIST_MIN;
	direction = norm3(diff3(light.position, point));
	int i = -1;
	previous = 1e20;
	while (++i < 256 && walk < SHADOW_DIST_MAX && intensity > SHADOW_INT_MIN)
	{
		delta = scene(add3(point, fmult3(direction, walk)), objs).dist;
		if (delta < SURFACE_DIST)
			return (0.f);
		y = (i == 0) ? 0.f : delta * delta / (2.0f * previous);
		d = sqrtf(delta * delta - y * y);
		intensity = fminf(intensity,
				d / (light.radius * fmaxf(0.0f, walk - y)));
		previous = delta;
		walk += delta;
	}
	float normal = dot3(direction, get_normal(point, objs));
	return(fminf(fmaxf(intensity, 0.f), 1.0f) * normal);
}
