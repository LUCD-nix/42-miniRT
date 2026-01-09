/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:51:17 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/04 16:51:20 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIGHTING_H
# define LIGHTING_H
# include "../vec3/vec3.h"

typedef struct s_colour
{
	unsigned int	a : 8;
	unsigned int	r : 8;
	unsigned int	g : 8;
	unsigned int	b : 8;
}	t_colour;

typedef struct s_point_light
{
	t_vec3		position;
	float		radius;
	float		intensity;
	t_colour	colour;
}	t_point_light;

typedef struct s_ambient_light
{
	t_vec3		direction;
	float		intensity;
	t_colour	colour;
}	t_ambient_light;

t_colour	add_light_to_obj(t_colour a, t_colour b, float intensity);

#endif // LIGHTING_H
