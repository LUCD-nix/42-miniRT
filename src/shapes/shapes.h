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

# ifndef MAX_SHAPES
#  define MAX_SHAPES 10
# endif //MAX_SHAPES

struct s_sphere
{
	t_vec3	position;
	float	radius;
};

struct s_box
{
	t_mat3	rotation;
	t_vec3	position;
	float	lx;
	float	ly;
	float	lz;
};

struct s_cylinder
{
	t_vec3	position;
	t_vec3	alignment;
	float	radius;
	float	height;
};

struct s_plane
{
	t_vec3	normal;
	float	height;
};

union u_shape
{
	struct s_sphere		sphere;
	struct s_box		box;
	struct s_cylinder	cylinder;
	struct s_plane		plane;
};

// typedef enum e_shape_tag
// {
// 	SPHERE,
// 	CYLINDER,
// 	PLANE,
// 	BOX
// }	t_shape_tag;
//
typedef struct s_shapes
{
	short			n_shapes;
	union u_shape	shapes[MAX_SHAPES];
	float			(*sdfs[MAX_SHAPES])(t_vec3, union u_shape);
	float			(*combine[MAX_SHAPES])(float, float, float);
	unsigned int	colours[MAX_SHAPES];
	float			smoothing[MAX_SHAPES];
}	t_shapes;

// Signed distance functions;
// adapted from : https://iquilezles.org/articles/distfunctions/
float	sphere_sdf(t_vec3 point, union u_shape ball);
float	plane_sdf(t_vec3 point, union u_shape surface);
float	box_sdf(t_vec3 point, union u_shape box);

// SDF combining operations (k is voided)
float	op_union(float d1, float d2, float k);
float	op_substraction(float d1, float d2, float k);
float	op_intersection(float d1, float d2, float k);
float	op_xor(float d1, float d2, float k);

// Smooth combining operations(k is the smoothing)
float	op_smooth_union(float d1, float d2, float k);
float	op_smooth_substraction(float d1, float d2, float k);
float	op_smooth_intersection(float d1, float d2, float k);
#endif // SHAPES_H
