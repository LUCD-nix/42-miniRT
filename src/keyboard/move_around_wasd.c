/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_around_wasd.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2025/11/30 14:09:22 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "keyboard.h"

static t_vec3	add_in_camera_space(t_camera *cam, t_vec3 delta)
{
	t_vec3	to_add;

	// NOTE : this is very general but could be simplified
	// due to sparseness of delta, if necessary
	to_add = fmult3(norm3(cam->screen_plane), delta.x);
	to_add = add3(fmult3(cam->u_3, delta.z), to_add);
	to_add = add3(fmult3(cam->v_3, delta.y), to_add);
	return (add3(cam->camera_pos, to_add));
}

void	move_around_wasd(int keycode, t_scene *scene)
{
	t_camera	*cam;
	t_vec3		delta;

	cam = scene->cam;
	delta = (t_vec3) {0.f, 0.f, 0.f};
	if (keycode == KB_W)
		delta = (t_vec3){MOVE_DELTA, 0.f, 0.f};
	if (keycode == KB_S)
		delta = (t_vec3){-MOVE_DELTA, 0.f, 0.f};
	if (keycode == KB_D)
		delta = (t_vec3){0.f, 0.f, MOVE_DELTA};
	if (keycode == KB_A)
		delta = (t_vec3){0.f, 0.f, -MOVE_DELTA};
	if (keycode == KB_LEFT_SHIFT)
		delta = (t_vec3){0.f, -MOVE_DELTA, 0.f};
	if (keycode == KB_SPACE)
		delta = (t_vec3){0.f, MOVE_DELTA, 0.f};
	cam->camera_pos = add_in_camera_space(cam, delta);
}
