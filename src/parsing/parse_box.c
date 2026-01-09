/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 22:44:24 by hlongin           #+#    #+#             */
/*   Updated: 2026/01/08 22:48:35 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	parse_box_geom(char **tokens, t_box_data *data)
{
	if (!parse_vec3(tokens[1], &data->pos))
		return (0);
	if (!parse_vec3(tokens[2], &data->rot))
		return (0);
	return (1);
}

static int	parse_box_dims(char **tokens, t_box_data *data)
{
	if (!parse_vec3(tokens[3], &data->dims))
		return (0);
	if (data->dims.x <= 0.0 || data->dims.y <= 0.0 || data->dims.z <= 0.0)
		return (0);
	if (!parse_color(tokens[4], &data->color))
		return (0);
	return (1);
}

static void	fill_box(t_scene *scene, t_box_data *data, t_combine_op *op)
{
	int	idx;

	idx = scene->shapes.n_shapes;
	scene->shapes.shapes[idx].box.position = data->pos;
	scene->shapes.shapes[idx].box.rotation = rot_mat3(data->rot.x,
			data->rot.y, data->rot.z);
	scene->shapes.shapes[idx].box.lx = (float)data->dims.x;
	scene->shapes.shapes[idx].box.ly = (float)data->dims.y;
	scene->shapes.shapes[idx].box.lz = (float)data->dims.z;
	scene->shapes.colours[idx] = data->color;
	scene->shapes.sdfs[idx] = &box_sdf;
	scene->shapes.combine[idx] = op->func;
	scene->shapes.smoothing[idx] = op->smoothing;
	scene->shapes.n_shapes++;
}

int	parse_box(char *line, t_scene *scene, int line_num)
{
	char			**tokens;
	t_box_data		data;
	t_combine_op	op;

	if (scene->shapes.n_shapes >= MAX_SHAPES)
		return (printf("Error\nLine %d: Max shapes reached\n", line_num), 0);
	tokens = ft_split(line, ' ');
	if (!tokens || !tokens[0] || !tokens[1] || !tokens[2] || !tokens[3]
		|| !tokens[4])
		return (free_split(tokens), 0);
	if (!parse_box_geom(tokens, &data))
		return (printf("Error\nLine %d: Invalid box geom\n", line_num),
			free_split(tokens), 0);
	if (!parse_box_dims(tokens, &data))
		return (printf("Error\nLine %d: Invalid box dims\n", line_num),
			free_split(tokens), 0);
	if (!parse_combine(tokens[5], &op))
		return (printf("Error\nLine %d: Invalid combine op\n", line_num),
			free_split(tokens), 0);
	fill_box(scene, &data, &op);
	return (free_split(tokens), 1);
}
