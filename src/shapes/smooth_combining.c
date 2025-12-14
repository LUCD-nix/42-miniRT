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

inline float	op_smooth_union(float d1, float d2, float k)
{
	float	h;

	k *= 4.0;
	h = fmaxf(k - fabsf(d1 - d2), 0.0f);
	return (fminf(d1, d2) - h * h * 0.25 / k);
}

inline float	op_smooth_substraction(float d1, float d2, float k)
{
	return (-op_smooth_union(-d1, d2, k));
}

inline float	op_smooth_intersection(float d1, float d2, float k)
{
	return (-op_smooth_union(-d1, -d2, k));
}
