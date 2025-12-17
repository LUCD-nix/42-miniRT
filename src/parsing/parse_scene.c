/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:33:11 by hlongin           #+#    #+#             */
/*   Updated: 2025/12/17 17:35:54 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_scene(const char *filename)
{
	int		fd;
	char	*line;
	int		line_num;
	t_scene	*scene;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line_num = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_num++;
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (line[0] == 'A')
			parse_ambient_light(line, scene, line_num);
		else if (line[0] == 'C')
			parse_camera(line, scene, line_num);
		else if (line[0] == 'L')
			parse_light(line, scene, line_num);
		else
		{
			printf("Error\nLine %d: Unknown identifier\n", line_num);
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
