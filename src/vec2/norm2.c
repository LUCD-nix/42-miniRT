/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:36:27 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/14 16:14:35 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec2.h"

t_vec2	norm2(t_vec2 v)
{
	t_vec2	res;
	float	length;

	length = length2(v);
	res = (t_vec2){
		.x = v.x / length,
		.y = v.y / length,
	};
	return (res);
}
