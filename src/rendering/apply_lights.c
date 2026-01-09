/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:33:38 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/12 17:33:38 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rendering.h"

t_colour	apply_lights(t_shapes *objs, t_vec3 ray, t_cdist colour_dist)
{
	t_colour	ambient_colour;
	t_colour	point_colour;
	t_vec3		normal;
	float		soft_shadows;
	float		diffuse;

	normal = get_normal(ray, objs);
	diffuse = fmaxf(
			dot3(normal, fmult3(objs->ambient.direction, -1.f)),
			0.0f);
	ambient_colour = add_light_to_obj(colour_dist.colour,
			objs->ambient.colour, diffuse * objs->ambient.intensity);
	soft_shadows = soft_shadow(objs->point, objs, ray);
	point_colour = add_light_to_obj(colour_dist.colour,
			objs->point.colour, soft_shadows * objs->point.intensity);
	ambient_colour = (t_colour){
		ambient_colour.a + point_colour.a,
		ambient_colour.r + point_colour.r,
		ambient_colour.g + point_colour.g,
		ambient_colour.b + point_colour.b,
	};
	return (ambient_colour);
}
