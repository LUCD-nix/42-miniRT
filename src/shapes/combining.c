/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combining.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:20:01 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/12 15:20:02 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "shapes.h"

// min
t_cdist	op_union(t_cdist d1, t_cdist d2, float k)
{
	(void) k;
	if (d1.dist < d2.dist)
		return (d1);
	return (d2);
}

// max (d1, -d2)
t_cdist	op_substraction(t_cdist d1, t_cdist d2, float k)
{
	(void) k;
	if (d1.dist > -d2.dist)
		return (d1);
	return ((t_cdist){-d2.dist, d2.colour});
}

	// max
t_cdist	op_intersection(t_cdist d1, t_cdist d2, float k)
{
	(void) k;
	if (d1.dist > d2.dist)
		return (d1);
	return (d2);
}

	// return (fmaxf(fminf(d1, d2), -fmaxf(d1, d2)));
t_cdist	op_xor(t_cdist d1, t_cdist d2, float k)
{
	(void) k;
	return (op_substraction(op_union(d1, d2, 0),
			op_intersection(d1, d2, 0), 0));
}
