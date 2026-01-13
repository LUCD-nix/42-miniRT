/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_combining.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:00:23 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/12 17:00:33 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "shapes.h"

t_colour	rgb_lerp(t_cdist o1, t_cdist o2)
{
	t_colour	a;
	t_colour	b;
	t_colour	res;
	float		frac;

	frac = (1 + (o1.dist - o2.dist) / (o2.dist + o1.dist)) / 2;
	a = o1.colour;
	b = o2.colour;
	res.a = a.a + (b.a - a.a) * frac;
	res.r = a.r + (b.r - a.r) * frac;
	res.g = a.g + (b.g - a.g) * frac;
	res.b = a.b + (b.b - a.b) * frac;
	return (res);
}

inline float	smooth_min(float d1, float d2, float k)
{
	float	h;

	k *= 4.0;
	h = fmaxf(k - fabsf(d1 - d2), 0.0f);
	return (fminf(d1, d2) - h * h * 0.25f / k);
}

t_cdist	op_smooth_union(t_cdist o1, t_cdist o2, float k)
{
	return ((t_cdist){
		smooth_min(o1.dist, o2.dist, k),
		rgb_lerp(o1, o2),
	});
}

// return (-op_smooth_union(-d1, d2, k));
t_cdist	op_smooth_substraction(t_cdist o1, t_cdist o2, float k)
{
	return ((t_cdist){
		-smooth_min(-o1.dist, o2.dist, k),
		o1.colour
	});
}

// return (-op_smooth_union(-d1, -d2, k));
t_cdist	op_smooth_intersection(t_cdist o1, t_cdist o2, float k)
{
	return ((t_cdist){
		-smooth_min(-o1.dist, -o2.dist, k),
		rgb_lerp(o1, o2),
	});
}
