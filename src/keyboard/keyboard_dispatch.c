/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_dispatch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2025/11/30 14:09:22 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "keyboard.h"

int		keyboard_dispatch(int keycode, void *param)
{
	t_scene	*scene;

	scene = (t_scene *) param;
	if (keycode == KB_ENTER)
		return (full_render(scene->objs, scene->cam, scene->img),
				mlx_put_image_to_window(scene->mlx, scene->mlx_window,
					scene->img->img, 0, 0),
				0);
	if (keycode == KB_ESCAPE)
		free_mlx_and_exit(scene);
	else if ((keycode >= KB_LEFT && keycode <= KB_DOWN)
			|| keycode == KB_Q
			|| keycode == KB_E)
		look_around_arrows(keycode, scene);
	else if (keycode == KB_W
			|| keycode == KB_A
			|| keycode == KB_S
			|| keycode == KB_D
			|| keycode == KB_SPACE
			|| keycode == KB_LEFT_SHIFT)
		move_around_wasd(keycode, scene);
	fast_render(scene->objs, scene->cam, scene->img);
	mlx_put_image_to_window(scene->mlx, scene->mlx_window,
		scene->img->img, 0, 0);
	return (0);
}

