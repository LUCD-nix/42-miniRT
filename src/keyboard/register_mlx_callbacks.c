/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_mlx_callbacks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2026/01/06 11:36:00 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"

void	register_mlx_callbacks(void *mlx_window, t_runtime *runtime)
{
	mlx_key_hook(mlx_window, &keyboard_dispatch, runtime);
	mlx_hook(mlx_window, 17, STRUCTURE_NOTIFY_MASK,
		&free_mlx_and_exit, runtime);
}
