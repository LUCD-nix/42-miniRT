/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:36:45 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/01 12:28:16 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H
# include <math.h>

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

// gives the length of the vector
float	length2(t_vec2 v);

// gives an all positive vector
t_vec2	abs2(t_vec2 v);

float	dot2(t_vec2 a, t_vec2 b);
t_vec2	add2(t_vec2 a, t_vec2 b);
t_vec2	max2f(t_vec2 v, float s);
t_vec2	fmult2(t_vec2 v, float s);
t_vec2	norm2(t_vec2 v);
t_vec2	diff2(t_vec2 a, t_vec2 b);

#endif // VEC2_H
