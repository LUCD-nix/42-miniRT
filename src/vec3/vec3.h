/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:36:45 by lucorrei          #+#    #+#             */
/*   Updated: 2025/11/28 14:36:45 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H
# include <math.h>

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

// gives a positive vector
t_vec3	abs3(t_vec3 v);

// gives the length of the vector
float	length3(t_vec3 v);

float	dot3(t_vec3 a, t_vec3 b);
t_vec3	norm3(t_vec3 v);
t_vec3	diff3(t_vec3 a, t_vec3 b);

#endif // VEC3_H
