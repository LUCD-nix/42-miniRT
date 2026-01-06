/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:07:33 by hlongin           #+#    #+#             */
/*   Updated: 2026/01/06 22:59:26 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	validate_plane_tokens(char **tokens, t_vec3 *coord, t_vec3 *normal,
		t_colour *color)
{
	if (!tokens[0] || !tokens[1] || !tokens[2] || !tokens[3])
		return (0);
	if (!parse_vec3(tokens[1], coord))
		return (0);
	if (!parse_vec3(tokens[2], normal))
		return (0);
	*normal = norm3(*normal);
	if (!parse_color(tokens[3], color))
		return (0);
	return (1);
}

static void	fill_plane(t_scene *scene, t_vec3 coord, t_vec3 normal,
		t_colour color)
{
	int	idx;

	idx = scene->shapes.n_shapes;
	scene->shapes.shapes[idx].plane.normal = normal;
	scene->shapes.shapes[idx].plane.height = dot3(coord, normal);
	scene->shapes.colours[idx] = color;
	scene->shapes.sdfs[idx] = &plane_sdf;
}

static void	fill_plane_combine(t_scene *scene, t_combine_op *op)
{
	int	idx;

	idx = scene->shapes.n_shapes;
	scene->shapes.combine[idx] = op->func;
	scene->shapes.smoothing[idx] = op->smoothing;
	scene->shapes.n_shapes++;
}

int	parse_plane(char *line, t_scene *scene, int line_num)
{
	char			**tokens;
	t_vec3			coord;
	t_vec3			normal;
	t_colour		color;
	t_combine_op	op;

	if (scene->shapes.n_shapes >= MAX_SHAPES)
		return (printf("Error\nLine %d: Max shapes reached\n", line_num), 0);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	if (!validate_plane_tokens(tokens, &coord, &normal, &color))
		return (printf("Error\nLine %d: Invalid plane data\n", line_num),
			free_split(tokens), 0);
	if (!parse_combine(tokens[4], &op))
		return (printf("Error\nLine %d: Invalid combine op\n", line_num),
			free_split(tokens), 0);
	fill_plane(scene, coord, normal, color);
	fill_plane_combine(scene, &op);
	return (free_split(tokens), 1);
}
