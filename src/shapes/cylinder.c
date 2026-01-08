/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:06:59 by lucorrei          #+#    #+#             */
/*   Updated: 2025/11/28 15:06:59 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "shapes.h"

static float cylinder_helper(float vert_dist, float cross_dist, float axis2)
{
	float	d;
	float	x2;
	float	y2;
	float	sign;

	x2 = cross_dist * cross_dist;
	y2 = vert_dist * vert_dist * axis2;
	if (fmaxf(cross_dist,vert_dist) < 0.0f)
		d = -fminf(x2, y2);
	else
		d = (cross_dist > 0.0f) * x2 + (vert_dist > 0.0f) * y2;
	sign = (d < 0.f) * -1.f + (d > 0.f) * 1.f;
	return (sign * sqrtf(fabsf(d)) / axis2);
}

float	cylinder_sdf(t_vec3 point, union u_shape cylinder)
{
	struct s_cylinder	cyl;
	t_vec3				to_base;
	float				axis2;
	float				proj;
	float				cross_dist;

	cyl = cylinder.cylinder;
	point = diff3(point, cyl.position);
	to_base = diff3(point, cyl.base);
	axis2 = dot3(cyl.axis,cyl.axis);
	proj = dot3(to_base,cyl.axis);
	cross_dist = length3(
			diff3(fmult3(to_base, axis2),
				fmult3(cyl.axis, proj)))
		- cyl.radius * axis2;
	return (cylinder_helper(fabsf(proj - axis2 * 0.5f) - axis2 * 0.5f,
				cross_dist,
				axis2));
}
