/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:36:27 by lucorrei          #+#    #+#             */
/*   Updated: 2025/11/28 14:36:27 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec3.h"

t_vec3	norm3(t_vec3 v)
{
	t_vec3	res;
	float	length;

	length = length3(v);
	res = (t_vec3){
		.x = v.x / length,
		.y = v.y / length,
		.z = v.z / length,
	};
	return (res);
}
