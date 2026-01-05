/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_around_arrows.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2025/11/30 14:09:22 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "keyboard.h"

static inline void	rotate_view(t_mat3 to_rotate, t_camera *cam)
{
	float	focus_dist;
	t_mat3	rotated;
	
	focus_dist = length3(cam->screen_plane);
	rotated = mat3mat3(to_rotate,(t_mat3){.rows = {
		norm3(cam->screen_plane),
		cam->v_3,
		cam->u_3
		}});
	cam->screen_plane = fmult3(rotated.rows[0], focus_dist);
	cam->v_3 = rotated.rows[1];
	cam->u_3 = rotated.rows[2];
}
void	look_around_arrows(int keycode, t_scene *scene)
{
	t_camera	*cam;
	t_mat3		to_rotate;

	cam = scene->cam;
	if (keycode == KB_UP)
		to_rotate = ROT_MAT_POS_PITCH;
	if (keycode == KB_DOWN)
		to_rotate = ROT_MAT_NEG_PITCH;
	if (keycode == KB_LEFT)
		to_rotate = ROT_MAT_POS_YAW;
	if (keycode == KB_RIGHT)
		to_rotate = ROT_MAT_NEG_YAW;
	if (keycode == KB_Q)
		to_rotate = ROT_MAT_NEG_ROLL;
	if (keycode == KB_E)
		to_rotate = ROT_MAT_POS_ROLL;
	rotate_view(to_rotate, cam);
}
