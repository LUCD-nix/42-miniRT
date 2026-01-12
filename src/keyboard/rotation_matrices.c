/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2026/01/06 11:38:31 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "keyboard.h"

t_mat3	rot_pitch(float theta)
{
	return ((t_mat3){
		.rows = {
			(t_vec3){cosf(theta), sinf(theta), 0},
		(t_vec3){-sinf(theta), cosf(theta), 0},
		(t_vec3){0, 0, 1},
		}});
}

t_mat3	rot_yaw(float theta)
{
	return ((t_mat3){
		.rows = {
			(t_vec3){cosf(theta), 0, -sinf(theta)},
		(t_vec3){0, 1, 0},
		(t_vec3){sinf(theta), 0, cosf(theta)},
		}});
}

t_mat3	rot_roll(float theta)
{
	return ((t_mat3){
		.rows = {
			(t_vec3){1, 0, 0},
		(t_vec3){0, cosf(theta), sinf(theta)},
		(t_vec3){0, -sinf(theta), cosf(theta)},
		}});
}
