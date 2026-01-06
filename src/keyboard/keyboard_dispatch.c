/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_dispatch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2026/01/06 11:39:09 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"

int		keyboard_dispatch(int keycode, void *param)
{
	t_scene_lucas	*scene;

	scene = (t_scene_lucas *) param;
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

