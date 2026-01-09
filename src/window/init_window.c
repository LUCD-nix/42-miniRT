/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:33:10 by lucorrei          #+#    #+#             */
/*   Updated: 2026/01/07 00:00:42 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "window.h"

void	init_window(void **mlx_ptr, void **window_ptr, t_img	*data)
{
	*mlx_ptr = mlx_init();
	if (*mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	*window_ptr = mlx_new_window(*mlx_ptr, SCREEN_X, SCREEN_Y, "miniRT");
	if (*window_ptr == NULL)
	{
		// TODO : write proper exit function w/ message
		mlx_destroy_display(*mlx_ptr);
		free(*mlx_ptr);
		exit(EXIT_FAILURE);
	}
	data->img = mlx_new_image(*mlx_ptr, SCREEN_X, SCREEN_Y);
	if (data->img == NULL)
	{
		mlx_destroy_window(*mlx_ptr, *window_ptr);
		mlx_destroy_display(*mlx_ptr);
		free(*mlx_ptr);
		exit(EXIT_FAILURE);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}
