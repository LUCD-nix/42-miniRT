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
	t_mat3	alignment;
	t_vec3	position;
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

typedef struct s_colour
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}	t_colour;

typedef struct s_cdist
{
	float			dist;
	unsigned int	colour;
}	t_cdist;


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
	t_cdist			(*combine[MAX_SHAPES])(t_cdist, t_cdist, float);
	unsigned int	colours[MAX_SHAPES];
	float			smoothing[MAX_SHAPES];
}	t_shapes;

// Signed distance functions;
// adapted from : https://iquilezles.org/articles/distfunctions/
float	sphere_sdf(t_vec3 point, union u_shape ball);
float	plane_sdf(t_vec3 point, union u_shape surface);
float	box_sdf(t_vec3 point, union u_shape box);
float	cylinder_sdf(t_vec3 point, union u_shape cylinder);

// SDF combining operations (k is voided)
t_cdist	op_union(t_cdist d1, t_cdist d2, float k);
t_cdist	op_substraction(t_cdist d1, t_cdist d2, float k);
t_cdist	op_intersection(t_cdist d1, t_cdist d2, float k);
t_cdist	op_xor(t_cdist d1, t_cdist d2, float k);

// Smooth combining operations(k is the smoothing)
t_cdist	op_smooth_union(t_cdist d1, t_cdist d2, float k);
t_cdist	op_smooth_substraction(t_cdist d1, t_cdist d2, float k);
t_cdist	op_smooth_intersection(t_cdist d1, t_cdist d2, float k);
#endif // SHAPES_H
