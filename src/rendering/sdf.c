/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:48:26 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/12 17:48:27 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rendering.h"

inline t_cdist	sdf(t_vec3	point, t_shapes *objs)
{
	short	i;
	t_cdist	temp;
	t_cdist	res;

	// NOTE : we have to ensure there's always at least a single obj to draw
	// but doing so here could be too expensive;
	res.dist = objs->sdfs[0](point, objs->shapes[0]);
	res.colour = objs->colours[0];
	i = 0;
	while(++i < objs->n_shapes)
	{
		temp.dist = objs->sdfs[i](point, objs->shapes[i]);
		temp.colour = objs->colours[i];
		res = objs->combine[i](res, temp, objs->smoothing[i]);
	}
	return (res);
}
