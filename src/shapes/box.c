/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:48:11 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/04 14:48:16 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "shapes.h"

float	box_sdf(t_vec3 p, union u_shape shape)
{
	t_vec3	q;
	float	inside;
	float	outside;

	p = trans_rot3(p, shape.box.position, shape.box.rotation);
	q = diff3(abs3(p), (t_vec3) {
		shape.box.lx / 2,
		shape.box.ly / 2,
		shape.box.lz / 2
	});
	outside = length3(max3f(q, 0.0f));
	inside = fminf(fmaxf(q.x, fmaxf(q.y, q.z)), 0.0f);
	return (outside + inside);
}
