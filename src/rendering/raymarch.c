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
#include <stddef.h>

inline unsigned int	raymarch(t_vec3 origin, t_vec3 direction, t_shapes *objs)
{
	float	dS;
	t_vec3	tmp;
	t_vec3	normal;
	size_t	i;

	dS = sdf(origin, objs);
	tmp = add3(origin, fmult3(direction, dS));
	i = -1;
	while (++i < MAX_STEPS)
	{
		dS = sdf(tmp, objs);
		if (fabsf(dS) < SURFACE_DIST)
			break ;
		tmp = add3(tmp, fmult3(direction, dS));
	}
	// background
	if (i == MAX_STEPS)
		return (0);
	// printf("sphere:{ %f, %f, %f }\n", tmp.x, tmp.y, tmp.z);
	normal = get_normal(tmp, objs);
	// printf("normal:{ %f, %f, %f }\n", normal.x, normal.y, normal.z);
	float diffuse = fmaxf(
		dot3(normal, (t_vec3){0.f, 1.f, 0.f}),
		0.0f
	);
	unsigned int light = (int)(diffuse * 255);
	return ((light << 24) + (light << 16)+  (light << 8) + light);
}

