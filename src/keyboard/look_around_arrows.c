/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_around_arrows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2026/01/06 11:37:22 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "keyboard.h"

static inline void	rotate_view(t_mat3 to_rotate, t_camera *cam)
{
	float	focus_dist;
	t_mat3	rotated;

	focus_dist = length3(cam->screen_plane);
	rotated = mat3mat3(to_rotate, (t_mat3){
			.rows = {
			norm3(cam->screen_plane),
			cam->v_3,
			cam->u_3
		}});
	cam->screen_plane = fmult3(rotated.rows[0], focus_dist);
	cam->v_3 = rotated.rows[1];
	cam->u_3 = rotated.rows[2];
}

void	look_around_arrows(int keycode, t_runtime *runtime)
{
	t_camera	*cam;
	t_mat3		to_rotate;

	cam = runtime->cam;
	if (keycode == KB_UP)
		to_rotate = rot_pitch(PI_12);
	if (keycode == KB_DOWN)
		to_rotate = rot_pitch(-PI_12);
	if (keycode == KB_LEFT)
		to_rotate = rot_yaw(PI_12);
	if (keycode == KB_RIGHT)
		to_rotate = rot_yaw(-PI_12);
	if (keycode == KB_Q)
		to_rotate = rot_roll(-PI_12);
	if (keycode == KB_E)
		to_rotate = rot_roll(PI_12);
	rotate_view(to_rotate, cam);
}
