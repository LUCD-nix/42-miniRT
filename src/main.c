/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2025/11/30 14:09:22 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "shapes/shapes.h"
#include "vec3/vec3.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;


inline void	put_pixel_to_img(t_img *data, int x, int y, int color)
{
	// TODO : consider manual inlining
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*window;
	t_img	data;

	mlx = mlx_init();
	if (mlx == NULL)
		exit(EXIT_FAILURE);
	window = mlx_new_window(mlx, 854, 480, "miniRT");
	if (window == NULL)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		exit(EXIT_FAILURE);
	}
	data.img = mlx_new_image(mlx, 854, 480);
	if (data.img == NULL)
	{
		mlx_destroy_window(mlx, window);
		mlx_destroy_display(mlx);
		free(mlx);
		exit(EXIT_FAILURE);
	}
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
		&data.line_length, &data.endian);
	mlx_put_image_to_window(mlx, window, data.img, 0, 0);
	mlx_loop(mlx);
}
