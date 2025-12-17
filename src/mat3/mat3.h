/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:51:17 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/04 16:51:20 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAT3_H
# define MAT3_H
# include "../vec3/vec3.h"

// FIXME : we're defining the struct in vec3.h to put translate + rotate in
// there, might want to change later

// typedef struct s_mat3
// {
// 	t_vec3 rows[3];
// }	t_mat3;
//
# define ID_MAT3 (t_mat3) {\
	.rows = {\
		(t_vec3){1, 0, 0},\
		(t_vec3){0, 1, 0},\
		(t_vec3){0, 0, 1},\
	}\
}\

t_mat3	mat3mat3(t_mat3 a, t_mat3 b);
t_vec3	mat3vec(t_mat3 a, t_vec3 v);
t_mat3	transp3(t_mat3 m);
t_mat3	rot_mat3(float rx, float ry, float rz);
t_mat3	rot_mat3_int(float a, float b, float g);

#endif // MATH3_H

