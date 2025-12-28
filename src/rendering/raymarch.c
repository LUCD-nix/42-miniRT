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

inline t_colour	raymarch(t_vec3 origin, t_vec3 direction, t_shapes *objs)
{
	t_cdist		colour_dist;
	t_vec3		ray;
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
		return (BACKGROUND);
	return (apply_lights(objs, ray, colour_dist));
}
