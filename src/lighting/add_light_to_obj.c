/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light_to_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:51:17 by lucorrei          #+#    #+#             */
/*   Updated: 2026/01/05 14:03:10 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

inline t_colour	add_light_to_obj(t_colour obj, t_colour light, float intensity)
{
	t_colour	res;

	res.a = obj.a * (intensity * light.a / 255.f);
	res.r = obj.r * (intensity * light.r / 255.f);
	res.g = obj.g * (intensity * light.g / 255.f);
	res.b = obj.b * (intensity * light.b / 255.f);
	return (res);
}