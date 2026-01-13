/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:33:11 by hlongin           #+#    #+#             */
/*   Updated: 2026/01/08 22:47:44 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	dispatch_line(char *line, t_scene *scene, int line_num)
{
	if (line[0] == 'A' && line[1] == ' ')
		return (parse_ambient(line, scene, line_num));
	else if (line[0] == 'C' && line[1] == ' ')
		return (parse_camera(line, scene, line_num));
	else if (line[0] == 'L' && line[1] == ' ')
		return (parse_light(line, scene, line_num));
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		return (parse_sphere(line, scene, line_num));
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		return (parse_plane(line, scene, line_num));
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		return (parse_cylinder(line, scene, line_num));
	else if (line[0] == 'b' && line[1] == 'o' && line[2] == ' ')
		return (parse_box(line, scene, line_num));
	else
		return (printf("Error\nLine %d: Unknown identifier\n", line_num), 0);
}

static int	validate_scene(t_scene *scene)
{
	if (!scene->has_ambient)
		return (printf("Error\nMissing ambient light (A)\n"), 0);
	if (!scene->has_camera)
		return (printf("Error\nMissing camera (C)\n"), 0);
	if (!scene->has_light)
		return (printf("Error\nMissing light (L)\n"), 0);
	return (1);
}

static int	parse_lines(int fd, t_scene *scene)
{
	char	*line;
	int		line_num;

	line_num = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_num++;
		if (line[0] != '\n' && !dispatch_line(line, scene, line_num))
			return (free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	parse_scene(const char *filename, t_scene *scene)
{
	int		fd;

	*scene = (t_scene){0};
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nCannot open file: %s\n", filename), 0);
	if (!parse_lines(fd, scene))
		return (close(fd), 0);
	close(fd);
	if (!validate_scene(scene))
		return (0);
	return (1);
}
