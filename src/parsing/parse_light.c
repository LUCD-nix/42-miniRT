/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:06:24 by hlongin           #+#    #+#             */
/*   Updated: 2025/12/17 22:19:07 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	validate_light_tokens(char **tokens, double *brightness,
		t_scene *scene, int line_num)
{
	if (!tokens[0] || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		return (0);
	if (!parse_vec3(tokens[1], &scene->light.position))
		return (printf("Error\nLine %d: Invalid coordinates\n", line_num), 0);
	if (!ft_atof_safe(tokens[2], brightness))
		return (0);
	if (*brightness < 0.0 || *brightness > 1.0)
		return (printf("Error\nLine %d: Brightness must be in [0.0, 1.0]\n",
				line_num), 0);
	if (!parse_color(tokens[3], &scene->light.color))
		return (printf("Error\nLine %d: Invalid color format\n", line_num), 0);
	return (1);
}

int	parse_light(char *line, t_scene *scene, int line_num)
{
	char	**tokens;
	double	brightness;

	if (scene->has_light)
		return (printf("Error\nLine %d: Duplicate light definition\n",
				line_num), 0);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	if (!validate_light_tokens(tokens, &brightness, scene, line_num))
		return (free_split(tokens), 0);
	scene->light.brightness = (float)brightness;
	scene->has_light = 1;
	return (free_split(tokens), 1);
}
