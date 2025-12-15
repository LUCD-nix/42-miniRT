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

static inline unsigned int	rgb_lerp(unsigned int c1, unsigned int c2, float t)
{
	t_colour	a;
	t_colour	b;
	t_colour	res;

	a = *(t_colour *)&c1;
	b = *(t_colour *)&c2;
	res.a = a.a + (b.a - a.a) * t;
	res.r = a.r + (b.r - a.r) * t;
	res.g = a.g + (b.g - a.g) * t;
	res.b = a.b + (b.b - a.b) * t;
	return (*(unsigned int *)&res);
}

static inline float	smooth_min(float d1, float d2, float k)
{
	float	h;

	k *= 4.0;
	h = fmaxf(k - fabsf(d1 - d2), 0.0f);
	return (fminf(d1, d2) - h * h * 0.25f / k);
}

inline t_cdist	op_smooth_union(t_cdist o1, t_cdist o2, float k)
{
	float	frac;

	frac = (1 + (o2.dist - o1.dist) / (o2.dist + o1.dist)) / 2;
	return ((t_cdist){
		smooth_min(o1.dist, o2.dist, k),
		rgb_lerp(o1.colour, o2.colour, frac),
	});
}

inline t_cdist	op_smooth_substraction(t_cdist o1, t_cdist o2, float k)
{
	// return (-op_smooth_union(-d1, d2, k));
	float	frac;

	frac = (1 + (o2.dist - o1.dist) / (o2.dist + o1.dist)) / 2;
	return ((t_cdist){
		-smooth_min(-o1.dist, o2.dist, k),
		rgb_lerp(o1.colour, o2.colour, frac),
	});
}

inline t_cdist	op_smooth_intersection(t_cdist o1, t_cdist o2, float k)
{
	// return (-op_smooth_union(-d1, -d2, k));
	float	frac;

	frac = (1 + (o2.dist - o1.dist) / (o2.dist + o1.dist)) / 2;
	return ((t_cdist){
		-smooth_min(-o1.dist, -o2.dist, k),
		rgb_lerp(o1.colour, o2.colour, frac),
	});
}
