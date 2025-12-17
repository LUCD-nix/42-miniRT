/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:08:09 by hlongin           #+#    #+#             */
/*   Updated: 2025/12/17 17:58:33 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../libft/get_next_line/get_next_line.h"
# include "../../libft/libft.h"
# include "../shapes/shapes.h"
# include "../vec3/vec3.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_ambient
{
	float			ratio;
	unsigned int	color;
}					t_ambient;

typedef struct s_camera
{
	t_vec3			position;
	t_vec3			orientation;
	int				fov;
}					t_camera;

typedef struct s_light
{
	t_vec3			position;
	float			brightness;
	unsigned int	color;
}					t_light;

typedef struct s_scene
{
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;
	int				has_ambient;
	int				has_camera;
	int				has_light;
	t_shapes		shapes;
}					t_scene;

double				ft_atof_safe(const char *str, double *result);
int					parse_vec3(char *str, t_vec3 *vec);
int					parse_color(char *str, unsigned int *color);
void				free_split(char **split);

int					parse_ambient(char *line, t_scene *scene, int line_num);
int					parse_camera(char *line, t_scene *scene, int line_num);
int					parse_light(char *line, t_scene *scene, int line_num);

int					parse_sphere(char *line, t_scene *scene, int line_num);

#endif