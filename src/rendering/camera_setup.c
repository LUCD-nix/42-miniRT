/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:36:04 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/17 16:36:06 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rendering.h"
#include <stdio.h>

static void	find_pitch_yaw(t_vec3 view_dir, float *pitch, float *yaw)
{
	*yaw = atan2f(-view_dir.z, view_dir.x);
	*pitch = asinf(view_dir.y);
}

t_camera	camera_setup(t_vec3 position, t_vec3 view_dir,
	float horizontal_fov)
{
	t_camera	res;
	t_mat3		rotation;
	float		pitch;
	float		yaw;
	float		focal_dist;

	res.camera_pos = position;
	find_pitch_yaw(view_dir, &pitch, &yaw);
	printf("pitch is : %f\n", pitch);
	printf("yaw is : %f\n", yaw);
	rotation = rot_mat3(0, yaw, pitch);
	res.u_3 = mat3vec(rotation, (t_vec3){0.f, 0.f, 1.f});
	res.v_3 = mat3vec(rotation, (t_vec3){0.f, 1.f, 0.f});
	focal_dist = SCREEN_LEN_X / 2 / tanf(horizontal_fov / 2);
	res.screen_plane = fmult3(view_dir, focal_dist);
	return (res);
}
