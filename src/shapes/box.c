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

inline static t_vec3	add3f(t_vec3 v, float s)
{
	return ((t_vec3){
		v.x + s,
		v.y + s,
		v.z + s
	});
}

inline static t_vec3	max3f(t_vec3 v, float s)
{
	return ((t_vec3){
		fmaxf(v.x, s),
		fmaxf(v.y, s),
		fmaxf(v.z, s),
	});
}


inline float	box_sdf(t_vec3 p, struct s_shape box)
{
	t_vec3	q;

	p = trans_rot3(p, box.position, box.box.rotation);
	q = diff3(abs3(p), (t_vec3) {
		box.box.width / 2,
		box.box.length / 2,
		box.box.height / 2
	});
	return (length3(add3f(
		max3f(q, 0.0),
		fminf(fmaxf(q.x, fmaxf(q.y, q.z)), 0.0f)
	)));
}
