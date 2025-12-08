/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_rot3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:48:49 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/08 16:49:02 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vec3.h"
#include "../mat3/mat3.h"

inline t_vec3	trans_rot3(t_vec3 point, t_vec3 new_origin, t_mat3 rotation)
{
	point = diff3(point, new_origin);
	return (mat3vec(rotation, point));
}
