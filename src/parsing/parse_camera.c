/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:44:00 by hlongin           #+#    #+#             */
/*   Updated: 2025/12/17 22:23:22 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	validate_camera_tokens(char **tokens, t_camera *cam, int line_num)
{
	if (!tokens[0] || !tokens[1] || !tokens[2] || !tokens[3] || tokens[4])
		return (0);
	if (!parse_vec3(tokens[1], &cam->position))
		return (printf("Error\nLine %d: Invalid position\n", line_num), 0);
	if (!parse_vec3(tokens[2], &cam->orientation))
		return (printf("Error\nLine %d: Invalid orientation\n", line_num), 0);
	if (!ft_atof_safe(tokens[3], &cam->fov))
		return (printf("Error\nLine %d: Invalid FOV format\n", line_num), 0);
	if (cam->fov < 0.0 || cam->fov > 180.0)
		return (printf("Error\nLine %d: FOV [0, 180]\n", line_num), 0);
	return (1);
}

int	parse_camera(char *line, t_scene *scene, int line_num)
{
	char		**tokens;
	t_camera	temp;
	double		fov_temp;

	if (scene->has_camera)
		return (printf("Error\nLine %d: Duplicate camera\n", line_num), 0);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	if (!validate_camera_tokens(tokens, &temp, line_num))
		return (free_split(tokens), 0);
	scene->camera.position = temp.position;
	scene->camera.orientation = norm3(temp.orientation);
	scene->camera.fov = temp.fov;
	scene->has_camera = 1;
	return (free_split(tokens), 1);
}
