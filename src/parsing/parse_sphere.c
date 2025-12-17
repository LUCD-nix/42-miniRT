/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:22:10 by hlongin           #+#    #+#             */
/*   Updated: 2025/12/17 22:28:12 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	validate_sphere_tokens(char **tokens, t_vec3 *position,
		double *diameter, unsigned int *color)
{
	if (!tokens[0] || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		return (0);
	if (!parse_vec3(tokens[1], position))
		return (0);
	if (!ft_atof_safe(tokens[2], diameter))
		return (0);
	if (*diameter <= 0.0)
		return (0);
	if (!parse_color(tokens[3], color))
		return (0);
	return (1);
}

int	parse_sphere(char *line, t_scene *scene, int line_num)
{
	char			**tokens;
	t_vec3			position;
	double			diameter;
	unsigned int	color;
	int				idx;

	if (scene->shapes.n_shapes >= MAX_SHAPES)
		return (printf("Error\nLine %d: Max shapes reached\n", line_num), 0);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	if (!validate_sphere_tokens(tokens, &position, &diameter, &color))
		return (printf("Error\nLine %d: Invalid sphere data\n", line_num),
			free_split(tokens), 0);
	idx = scene->shapes.n_shapes;
	scene->shapes.shapes[idx].sphere.position = position;
	scene->shapes.shapes[idx].sphere.radius = (float)(diameter / 2.0);
	scene->shapes.colours[idx] = color;
	scene->shapes.sdfs[idx] = &sphere_sdf;
	scene->shapes.combine[idx] = &op_union;
	scene->shapes.smoothing[idx] = 0.0f;
	scene->shapes.n_shapes++;
	return (free_split(tokens), 1);
}
