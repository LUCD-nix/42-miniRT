/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_mlx_callbacks.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2025/11/30 14:09:22 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "keyboard.h"

void	register_mlx_callbacks(void *mlx_window, t_scene *scene)
{
	mlx_key_hook(mlx_window, &keyboard_dispatch, scene);
	mlx_hook(mlx_window, 17, STRUCTURE_NOTIFY_MASK,
		&free_mlx_and_exit, scene);
}
