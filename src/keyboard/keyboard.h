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

# define COS_PI_12 0.965925826
# define SIN_PI_12 0.258819045

# define ROT_MAT_NEG_PITCH (t_mat3) {\
	.rows = {\
		(t_vec3){COS_PI_12, -SIN_PI_12, 0},\
		(t_vec3){SIN_PI_12, COS_PI_12, 0},\
		(t_vec3){0, 0, 1},\
	}\
}

# define ROT_MAT_POS_PITCH (t_mat3) {\
	.rows = {\
		(t_vec3){COS_PI_12, SIN_PI_12, 0},\
		(t_vec3){-SIN_PI_12, COS_PI_12, 0},\
		(t_vec3){0, 0, 1},\
	}\
}

# define ROT_MAT_NEG_YAW (t_mat3) {\
	.rows = {\
		(t_vec3){COS_PI_12, 0, SIN_PI_12},\
		(t_vec3){0, 1, 0},\
		(t_vec3){-SIN_PI_12, 0, COS_PI_12},\
	}\
}

# define ROT_MAT_POS_YAW (t_mat3) {\
	.rows = {\
		(t_vec3){COS_PI_12, 0, -SIN_PI_12},\
		(t_vec3){0, 1, 0},\
		(t_vec3){SIN_PI_12, 0, COS_PI_12},\
	}\
}

# define ROT_MAT_POS_ROLL (t_mat3) {\
	.rows = {\
		(t_vec3){1, 0, 0},\
		(t_vec3){0, COS_PI_12, SIN_PI_12},\
		(t_vec3){0, -SIN_PI_12, COS_PI_12},\
	}\
}

# define ROT_MAT_NEG_ROLL (t_mat3) {\
	.rows = {\
		(t_vec3){1, 0, 0},\
		(t_vec3){0, COS_PI_12, -SIN_PI_12},\
		(t_vec3){0, SIN_PI_12, COS_PI_12},\
	}\
}

typedef struct s_scene_lucas
{
	t_shapes	*objs;
	t_camera	*cam;
	void		*mlx;
	void		*mlx_window;
	t_img		*img;
}	t_scene_lucas;

void	register_mlx_callbacks(void *mlx_window, t_scene_lucas *scene);
int		keyboard_dispatch(int keycode, void *param);
int		free_mlx_and_exit(t_scene_lucas *scene);
void	look_around_arrows(int keycode, t_scene_lucas *scene);
void	move_around_wasd(int keycode, t_scene_lucas *scene);

#endif // KEYBOARD_H
