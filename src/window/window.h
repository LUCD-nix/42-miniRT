/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:33:12 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/12 14:33:12 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
#include "../../minilibx-linux/mlx.h"
#include <stdlib.h>
// #define SCREEN_X 1920
// #define SCREEN_Y 1080
#define SCREEN_X 854
#define SCREEN_Y 480
// #define SCREEN_X 160
// #define SCREEN_Y 90

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

void	init_window(void **mlx_ptr, void **window_ptr, t_img	*data);

#endif // WINDOW_H
