/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:08:09 by hlongin           #+#    #+#             */
/*   Updated: 2026/01/06 23:02:57 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../libft/get_next_line/get_next_line.h"
# include "../../libft/libft.h"
# include "../shapes/shapes.h"
# include "../vec3/vec3.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef t_cdist		(*t_combine_fn)(t_cdist, t_cdist, float);

typedef struct s_combine_op
{
	t_combine_fn	func;
	float			smoothing;
}					t_combine_op;

typedef struct s_cyl_data
{
	t_vec3			pos;
	t_vec3			orient;
	double			dims[2];
	t_colour		color;
}					t_cyl_data;

typedef struct s_ambient
{
	float			ratio;
	t_colour		color;
}					t_ambient;

typedef struct s_camera_data
{
	t_vec3			position;
	t_vec3			orientation;
	double			fov;
}					t_camera_data;

typedef struct s_light
{
	t_vec3			position;
	float			brightness;
	t_colour		color;
}					t_light;

typedef struct s_scene
{
	t_ambient		ambient;
	t_camera_data	camera;
	t_light			light;
	int				has_ambient;
	int				has_camera;
	int				has_light;
	t_shapes		shapes;
}					t_scene;

double				ft_atof_safe(const char *str, double *result);
int					parse_vec3(char *str, t_vec3 *vec);
int					parse_color(char *str, t_colour *color);
void				free_split(char **split);
t_scene				*parse_scene(const char *filename);

int					parse_ambient(char *line, t_scene *scene, int line_num);
int					parse_camera(char *line, t_scene *scene, int line_num);
int					parse_light(char *line, t_scene *scene, int line_num);

int					parse_sphere(char *line, t_scene *scene, int line_num);
int					parse_plane(char *line, t_scene *scene, int line_num);
int					parse_cylinder(char *line, t_scene *scene, int line_num);
void				dump_scene(t_scene *s);

int					parse_combine(char *str, t_combine_op *op);
#endif