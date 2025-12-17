/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:41:56 by hlongin           #+#    #+#             */
/*   Updated: 2025/12/17 22:17:12 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	validate_ambient_tokens(char **tokens, double *ratio,
		t_scene *scene, int line_num)
{
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3])
		return (0);
	if (!ft_atof_safe(tokens[1], ratio))
		return (0);
	if (*ratio < 0.0 || *ratio > 1.0)
	{
		printf("Error\nLine %d: Ambient ratio must be in [0.0, 1.0]\n",
			line_num);
		return (0);
	}
	if (!parse_color(tokens[2], &scene->ambient.color))
	{
		printf("Error\nLine %d: Invalid color format\n", line_num);
		return (0);
	}
	return (1);
}

int	parse_ambient(char *line, t_scene *scene, int line_num)
{
	char	**tokens;
	double	ratio;

	if (scene->has_ambient)
		return (printf("Error\nLine %d: Duplicate ambient light\n", line_num),
			0);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	if (!validate_ambient_tokens(tokens, &ratio, scene, line_num))
		return (free_split(tokens), 0);
	scene->ambient.ratio = (float)ratio;
	scene->has_ambient = 1;
	return (free_split(tokens), 1);
}
