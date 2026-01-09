/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 23:08:00 by hlongin           #+#    #+#             */
/*   Updated: 2026/01/06 23:02:04 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	parse_cyl_geom(char **tokens, t_cyl_data *data)
{
	if (!parse_vec3(tokens[1], &data->pos))
		return (0);
	if (!parse_vec3(tokens[2], &data->orient))
		return (0);
	data->orient = norm3(data->orient);
	return (1);
}

static int	parse_cyl_dims(char **tokens, t_cyl_data *data)
{
	if (!ft_atof_safe(tokens[3], &data->dims[0]) || data->dims[0] <= 0.0)
		return (0);
	if (!ft_atof_safe(tokens[4], &data->dims[1]) || data->dims[1] <= 0.0)
		return (0);
	if (!parse_color(tokens[5], &data->color))
		return (0);
	return (1);
}

static void	fill_cylinder(t_scene *scene, t_cyl_data *data, t_combine_op *op)
{
	int	idx;

	idx = scene->shapes.n_shapes;
	scene->shapes.shapes[idx].cylinder.position = data->pos;
	scene->shapes.shapes[idx].cylinder.axis = (t_vec3) {0.0f, 0.0f, 5.f};
	scene->shapes.shapes[idx].cylinder.radius = (float)(data->dims[0] / 2.0);
	scene->shapes.shapes[idx].cylinder.base = (t_vec3) {0.f, 0.f, -2.5f};
	scene->shapes.colours[idx] = data->color;
	scene->shapes.sdfs[idx] = &cylinder_sdf;
	scene->shapes.combine[idx] = op->func;
	scene->shapes.smoothing[idx] = op->smoothing;
	scene->shapes.n_shapes++;
}

int	parse_cylinder(char *line, t_scene *scene, int line_num)
{
	char			**tokens;
	t_cyl_data		data;
	t_combine_op	op;

	if (scene->shapes.n_shapes >= MAX_SHAPES)
		return (printf("Error\nLine %d: Max shapes reached\n", line_num), 0);
	tokens = ft_split(line, ' ');
	if (!tokens || !tokens[0] || !tokens[1] || !tokens[2] || !tokens[3]
		|| !tokens[4] || !tokens[5])
		return (free_split(tokens), 0);
	if (!parse_cyl_geom(tokens, &data))
		return (printf("Error\nLine %d: Invalid cylinder geom\n", line_num),
			free_split(tokens), 0);
	if (!parse_cyl_dims(tokens, &data))
		return (printf("Error\nLine %d: Invalid cylinder dims\n", line_num),
			free_split(tokens), 0);
	if (!parse_combine(tokens[6], &op))
		return (printf("Error\nLine %d: Invalid combine op\n", line_num),
			free_split(tokens), 0);
	fill_cylinder(scene, &data, &op);
	return (free_split(tokens), 1);
}
