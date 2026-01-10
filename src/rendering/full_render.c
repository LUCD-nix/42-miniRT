/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2026/01/06 23:53:33 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rendering.h"
#include <stdio.h>
#include <sys/time.h>

static size_t	get_ms_time_diff(struct timeval start_time)
{
	struct timeval		current_time;
	unsigned long int	res;

	gettimeofday(&current_time, NULL);
	res = (current_time.tv_sec - start_time.tv_sec) * 1000;
	res += (current_time.tv_usec - start_time.tv_usec) / 1000;
	return (res);
}

void	full_render(t_shapes *objs, t_camera *cam, t_img *data)
{
	size_t			i;
	size_t			j;
	struct timeval	start_time;
	t_vec3			rd;
	t_colour		temp;

	if (gettimeofday(&start_time, NULL) == -1)
	{
		printf("Fatal, couldn't get time of day\n");
		return ;
	}
	i = -1;
	while (++i < SCREEN_Y)
	{
		j = -1;
		while (++j < SCREEN_X)
		{
			rd = get_uv(j, i, cam);
			temp = raymarch(cam->camera_pos, rd, objs);
			put_pixel_to_img(data, j, i, temp);
		}
	}
	j = get_ms_time_diff(start_time);
	printf("Finished rendering in %zu.%zu seconds\n", j / 1000, j % 1000);
}
