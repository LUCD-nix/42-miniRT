/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 23:08:00 by hlongin           #+#    #+#             */
/*   Updated: 2026/01/06 10:33:28 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	parse_cylinder_geom(char **tokens, t_vec3 *pos, t_vec3 *orient)
{
	if (!parse_vec3(tokens[1], pos))
		return (0);
	if (!parse_vec3(tokens[2], orient))
		return (0);
	*orient = norm3(*orient);
	return (1);
}

static int	parse_cylinder_dims(char **tokens, double *diameter, double *height)
{
	if (!ft_atof_safe(tokens[3], diameter))
		return (0);
	if (*diameter <= 0.0)
		return (0);
	if (!ft_atof_safe(tokens[4], height))
		return (0);
	if (*height <= 0.0)
		return (0);
	return (1);
}

static void	fill_cylinder(t_scene *scene, t_vec3 pos, double *dims,
		t_colour color)
{
	int	idx;

	idx = scene->shapes.n_shapes;
	scene->shapes.shapes[idx].cylinder.position = pos;
	scene->shapes.shapes[idx].cylinder.alignment = ID_MAT3;
	scene->shapes.shapes[idx].cylinder.radius = (float)(dims[0] / 2.0);
	scene->shapes.shapes[idx].cylinder.height = (float)dims[1];
	scene->shapes.colours[idx] = color;
	scene->shapes.sdfs[idx] = &cylinder_sdf;
	scene->shapes.combine[idx] = &op_union;
	scene->shapes.smoothing[idx] = 0.0f;
	scene->shapes.n_shapes++;
}

int	parse_cylinder(char *line, t_scene *scene, int line_num)
{
	char			**tokens;
	t_vec3			pos;
	t_vec3			orient;
	double			dims[2];
	t_colour		color;

	if (scene->shapes.n_shapes >= MAX_SHAPES)
		return (printf("Error\nLine %d: Max shapes reached\n", line_num), 0);
	tokens = ft_split(line, ' ');
	if (!tokens || !tokens[0] || !tokens[1] || !tokens[2] || !tokens[3]
		|| !tokens[4] || !tokens[5] || tokens[6])
		return (free_split(tokens), 0);
	if (!parse_cylinder_geom(tokens, &pos, &orient))
		return (printf("Error\nLine %d: Invalid cylinder data\n", line_num),
			free_split(tokens), 0);
	if (!parse_cylinder_dims(tokens, &dims[0], &dims[1]))
		return (printf("Error\nLine %d: Invalid cylinder data\n", line_num),
			free_split(tokens), 0);
	if (!parse_color(tokens[5], &color))
		return (printf("Error\nLine %d: Invalid cylinder data\n", line_num),
			free_split(tokens), 0);
	fill_cylinder(scene, pos, dims, color);
	return (free_split(tokens), 1);
}
