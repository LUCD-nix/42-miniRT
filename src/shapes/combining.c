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

inline float	op_union(float d1, float d2, float k)
{
	(void) k;
	return (fminf(d1, d2));
}

inline float	op_substraction(float d1, float d2, float k)
{
	(void) k;
	// NOTE : test, might want to change which has negative sign later
	return (fmaxf(d1, -d2));
}

inline float	op_intersection(float d1, float d2, float k)
{
	(void) k;
	return (fmaxf(d1, d2));
}

inline float	op_xor(float d1, float d2, float k)
{
	(void) k;
	return (fmaxf(fminf(d1, d2), -fmaxf(d1, d2)));
}
