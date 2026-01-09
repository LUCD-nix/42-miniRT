/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_mat3_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:50:56 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/17 16:53:08 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mat3.h"

// This is the same as rot_mat3 but we're using intrinsic rotation
// https://en.wikipedia.org/wiki/Rotation_matrix#In_three_dimensions
t_mat3	rot_mat3_int(float a, float b, float g)
{
	t_mat3	rot_x;
	t_mat3	rot_y;
	t_mat3	rot_z;

	rot_x = (t_mat3){.rows = {
		(t_vec3){1, 0, 0},
		(t_vec3){0, cosf(a), -sinf(a)},
		(t_vec3){0, sinf(a), cosf(a)}
	}};
	rot_y = (t_mat3){.rows = {
		(t_vec3){cosf(b), 0, sinf(b)},
		(t_vec3){0, 1, 0},
		(t_vec3){-sinf(b), 0, cosf(b)}
	}};
	rot_z = (t_mat3){.rows = {
		(t_vec3){cosf(g), -sinf(g), 0},
		(t_vec3){sinf(g), cosf(g), 0},
		(t_vec3){0, 0, 1}
	}};
	return (mat3mat3(rot_z, mat3mat3(rot_y, rot_x)));
}
