/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:06:59 by lucorrei          #+#    #+#             */
/*   Updated: 2025/11/28 15:06:59 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H
# include "../vec3/vec3.h"
# include "../mat3/mat3.h"

struct s_sphere
{
	float	radius;
};

struct s_box
{
	t_mat3	rotation;
	float	width;
	float	length;
	float	height;
};

struct s_cylinder
{
	float	radius;
	float	height;
};

struct s_plane
{
	t_vec3	normal;
	float	height;
};

typedef enum e_shape_tag
{
	SPHERE,
	CYLINDER,
	PLANE,
	BRICK
}	t_shape_tag;

typedef struct s_shape
{
// TODO : we might be able to anonymize each shape struct, would be ergonomic
	t_shape_tag			type;
	t_vec3				position;
	unsigned char		colour[3];
	union
	{
		struct s_sphere		sphere;
		struct s_box		box;
		struct s_plane		plane;
		struct s_cylinder	cylinder;
	};
}	t_shape;

float	sphere_sdf(t_vec3 point, t_shape ball);
float	plane_sdf(t_vec3 point, t_shape surface);
float	box_sdf(t_vec3 point, t_shape box);

#endif // SHAPES_H
