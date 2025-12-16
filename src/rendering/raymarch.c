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

inline unsigned int	raymarch(t_vec3 origin, t_vec3 direction, t_shapes *objs)
{
	t_cdist		colour_dist;
	t_vec3		tmp;
	t_vec3		normal;
	t_colour	obj_colour;
	size_t		i;

	colour_dist = sdf(origin, objs);
	tmp = add3(origin, fmult3(direction, colour_dist.dist));
	i = -1;
	while (++i < MAX_STEPS)
	{
		// TODO : test if += to dist and always marching from orig is better
		colour_dist = sdf(tmp, objs);
		if (fabsf(colour_dist.dist) < SURFACE_DIST)
			break ;
		tmp = add3(tmp, fmult3(direction, colour_dist.dist));
	}
	// background
	if (i == MAX_STEPS)
		return (0);
	normal = get_normal(tmp, objs);
	float diffuse = fmaxf(
		dot3(normal, (t_vec3){0.0f, M_SQRT1_2, M_SQRT1_2}),
		0.0f
	);
	obj_colour = *(t_colour *)&colour_dist.colour;
	obj_colour.a *= diffuse;
	obj_colour.r *= diffuse;
	obj_colour.g *= diffuse;
	obj_colour.b *= diffuse;
	return (*(unsigned int *)&obj_colour);
}
