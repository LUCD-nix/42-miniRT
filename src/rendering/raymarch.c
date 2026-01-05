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
#include <math.h>
#include <stddef.h>

t_colour	raymarch(t_vec3 origin, t_vec3 direction, t_shapes *objs)
{
	t_cdist		colour_dist;
	t_vec3		ray;
<<<<<<< HEAD
=======
	t_vec3		normal;
	t_colour	res_colour;
>>>>>>> origin/point-light
	size_t		i;
	float		walk;

	i = -1;
	colour_dist = scene(origin, objs);
	walk = colour_dist.dist;
	while (++i < MAX_STEPS)
	{
		ray = add3(origin, fmult3(direction, walk));
		colour_dist = scene(ray, objs);
		walk += colour_dist.dist;
		if (fabsf(colour_dist.dist) < SURFACE_DIST)
			break ;
	}
	if (i == MAX_STEPS)
<<<<<<< HEAD
		return (BACKGROUND);
	return (apply_lights(objs, ray, colour_dist));
=======
		return ((t_colour){0, 0, 0, 0});
	normal = get_normal(ray, objs);
	float diffuse = fmaxf(
		dot3(normal, fmult3(objs->ambient.direction, -1.f)),
		0.0f
	);
	res_colour = add_light_to_obj(colour_dist.colour,
		objs->ambient.colour, diffuse * objs->ambient.intensity);
	float soft_shadows = soft_shadow(objs->point, objs, ray);
	t_colour point_colour = add_light_to_obj(colour_dist.colour,
		objs->point.colour, soft_shadows * objs->point.intensity);
	res_colour = (t_colour) {
		res_colour.a + point_colour.a,
		res_colour.r + point_colour.r,
		res_colour.g + point_colour.g,
		res_colour.b + point_colour.b,
	};
	return (res_colour);
>>>>>>> origin/point-light
}
