/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_and_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2026/01/06 23:59:48 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"

int	free_mlx_and_exit(t_scene_lucas *scene)
{
	void	*mlx;
	t_img	*image_data;

	image_data = scene->img;
	mlx = scene->mlx;
	mlx_destroy_image(mlx, image_data->img);
	mlx_destroy_window(mlx, scene->mlx_window);
	mlx_destroy_display(mlx);
	free(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
