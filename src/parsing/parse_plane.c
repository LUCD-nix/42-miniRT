/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:07:33 by hlongin           #+#    #+#             */
/*   Updated: 2025/12/30 23:05:07 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	validate_plane_tokens(char **tokens, t_vec3 *coord, t_vec3 *normal,
		unsigned int *color)
{
	if (!tokens[0] || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
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

int	parse_plane(char *line, t_scene *scene, int line_num)
{
	char			**tokens;
	t_vec3			coord;
	t_vec3			normal;
	unsigned int	color;
	int				idx;

	if (scene->shapes.n_shapes >= MAX_SHAPES)
		return (printf("Error\nLine %d: Max shapes reached\n", line_num), 0);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	if (!validate_plane_tokens(tokens, &coord, &normal, &color))
		return (printf("Error\nLine %d: Invalid plane data\n", line_num),
			free_split(tokens), 0);
	idx = scene->shapes.n_shapes;
	scene->shapes.shapes[idx].plane.normal = normal;
	scene->shapes.shapes[idx].plane.height = dot3(coord, normal);
	scene->shapes.colours[idx] = color;
	scene->shapes.sdfs[idx] = &plane_sdf;
	scene->shapes.combine[idx] = &op_union;
	scene->shapes.smoothing[idx] = 0.0f;
	scene->shapes.n_shapes++;
	return (free_split(tokens), 1);
}
