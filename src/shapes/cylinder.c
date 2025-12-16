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
#include "../vec2/vec2.h"

float	cylinder_sdf(t_vec3 point, union u_shape shape)
{
	t_vec2	d;
	t_vec3	p;

	// FIXME : 
	// This is overkill, the cylinder does not need full 3D rotation
	// consider implementing the arbitrary cylinder by Inigo
	p = trans_rot3(point, shape.cylinder.position,
				shape.cylinder.alignment);

	d = (t_vec2){
		sqrtf(p.x * p.x + p.z * p.z),
		p.y
	};
	d = abs2(d);
	d = diff2(d, (t_vec2){
		shape.cylinder.radius,
		shape.cylinder.height / 2
	});
	return fminf(fmaxf(d.x,d.y),0.0) + length2(max2f(d,0.0));
}
