/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:41:56 by hlongin           #+#    #+#             */
/*   Updated: 2025/12/17 17:58:12 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_ambient(char *line, t_scene *scene, int line_num)
{
	char	**tokens;
	double	ratio;
	int		success;

	if (scene->has_ambient)
	{
		printf("Error\nLine %d: Duplicate ambient light definition\n",
			line_num);
		return (0);
	}
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	success = 1;
	if (!tokens[0] || !tokens[1] || tokens[2])
		success = 0;
	else if (!ft_atof_safe(tokens[0], &ratio))
		success = 0;
	else if (ratio < 0.0 || ratio > 1.0)
	{
		printf("Error\nLine %d: Ambient ratio must be in [0.0, 1.0]\n",
			line_num);
		success = 0;
	}
	else if (!parse_color(tokens[2], &scene->ambient.color))
	{
		printf("Error\nLine %d: Invalid color format\n", line_num);
		success = 0;
	}
	if (success)
	{
		scene->ambient.ratio = (float)ratio;
		scene->has_ambient = 1;
	}
	return (free_split(tokens), success);
}
