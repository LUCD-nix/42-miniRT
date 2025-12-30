/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2025/11/30 14:09:22 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rendering.h"

static inline void	put_pixel_to_img(t_img *data, int x, int y, t_colour colour)
{
	// TODO : Refactor
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = ((unsigned int)colour.r << 16)
		+  ((unsigned int)colour.g << 8)
		+ (unsigned int)colour.b;
}

static void	big_pixel(t_colour colour, size_t px, size_t py, t_img *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			put_pixel_to_img(data, py + j, px + i, colour);
			j++;
		}
		i++;
	}
}

void	fast_render(t_shapes *objs, t_camera cam, t_img *data)
{
	int			i;
	int			j;
	t_vec3		rd;
	t_colour	temp;

	i = 0;
	while (i < SCREEN_Y - 10)
	{
		j = 0;
		while (j < SCREEN_X - 10)
		{
			rd = get_uv(j + 5, i + 5, cam);
			temp = raymarch(cam.camera_pos, rd, objs);
			big_pixel(temp, i, j, data);
			j += 10;
		}
		i += 10;
	}
}
