/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:33:36 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/14 14:01:28 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rendering.h"

	// eps needs to be bigger than SURFACE_DIST for sdf(pos) ~= 0
	// Could go to a more accurate impl (Inigo Quilez)
	// but would require more sdf calls
t_vec3	get_normal(t_vec3 point, t_shapes *objs)
{
	t_vec3	normal;
	float	eps;

	eps = EPS_NORMAL;
	normal = (t_vec3){
		scene(add3(point, (t_vec3){eps, 0, 0}), objs).dist,
		scene(add3(point, (t_vec3){0, eps, 0}), objs).dist,
		scene(add3(point, (t_vec3){0, 0, eps}), objs).dist,
	};
	return (norm3(normal));
}
