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
#define SHADOW_DIST_MIN 0.1f
#define SHADOW_DIST_MAX 10.f

// see if we can get these to work, same principle but reduces the banding
// and has a darker penumbra
// inline float	soft_shadow(t_point_light light, t_shapes *objs, t_vec3 point)
// {
// 	t_vec3	direction;
// 	float	intensity;
// 	float	delta;
// 	float	t;
// 	int		i;
//
// 	direction = norm3(diff3(light.position, point));
// 	intensity = 1.0f;
// 	t = SHADOW_DIST_MIN;
// 	i = -1;
// 	while (++i < 256 && t < SHADOW_DIST_MAX)
// 	{
// 		delta = scene(add3(point, fmult3(direction, t)), objs).dist;
// 		intensity = fminf( intensity, delta / (light.radius * t));
// 		// TODO : maybe use clamp here
// 		t += fabsf(delta);
// 		if (intensity<-1.0 || t > SHADOW_DIST_MAX)
// 			break;
// 	}
// 	intensity = fmaxf(intensity, -1.0);
// 	return (0.25*(1.0 + intensity) * (1.0 + intensity) * (2.0 - intensity));
// }
float soft_shadow(t_point_light light, t_shapes *objs, t_vec3 point)
{
	float res = 1.0;
	float t = SHADOW_DIST_MIN;
	float k = light.radius;

	t_vec3 direction = norm3(diff3(light.position, point));
	for( int i=0; i<256 && t<SHADOW_DIST_MAX; i++ )
	{
		float h = scene(add3(point, fmult3(direction, t)), objs).dist;
		if( h < SURFACE_DIST )
			return 0.0;
		res = fminf( res, k*h/t );
		t += h;
	}
	return res;
}
