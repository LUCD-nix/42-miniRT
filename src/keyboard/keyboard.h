/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2026/01/06 11:38:31 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# include "../rendering/rendering.h"
# include "../window/window.h"
# include <math.h>
// Keymaps from here :
// # include <X11/keysymdef.h>

# define KB_ESCAPE 0xff1b
# define KB_SPACE 0x0020
# define KB_LEFT 0xff51
# define KB_UP 0xff52
# define KB_RIGHT 0xff53
# define KB_DOWN 0xff54
# define KB_Q 0x0071
# define KB_E 0x0065
# define KB_W 0x0077
# define KB_A 0x0061
# define KB_S 0x0073
# define KB_D 0x0064
# define KB_LEFT_SHIFT 0xffe1
# define KB_LEFT_CTRL 0xffe3
# define KB_ENTER 0xff0d

# define MOVE_DELTA 0.3f

# define STRUCTURE_NOTIFY_MASK 131072

# define PI_12 0.261799388f

typedef struct s_runtime
{
	t_shapes	*objs;
	t_camera	*cam;
	void		*mlx;
	void		*mlx_window;
	t_img		*img;
}	t_runtime;

t_mat3	rot_roll(float theta);
t_mat3	rot_yaw(float theta);
t_mat3	rot_pitch(float theta);
void	register_mlx_callbacks(void *mlx_window, t_runtime *scene);
int		keyboard_dispatch(int keycode, void *param);
int		free_mlx_and_exit(t_runtime *scene);
void	look_around_arrows(int keycode, t_runtime *scene);
void	move_around_wasd(int keycode, t_runtime *scene);

#endif // KEYBOARD_H
