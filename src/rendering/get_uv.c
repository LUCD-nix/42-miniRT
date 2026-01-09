/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:49:34 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/17 13:49:40 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rendering.h"
#include <stddef.h>

t_vec3	get_uv(size_t px, size_t py, t_camera *cam)
{
	t_vec3	res;
	float	u;
	float	v;

	u = ((float) px / SCREEN_X - 0.5) * (16.f / 9.f);
	v = (float) py / SCREEN_Y - 0.5;
	res = fmult3(cam->u_3, u);
	res = diff3(res, fmult3(cam->v_3, v));
	res = add3(res, cam->screen_plane);
	return (norm3(res));
}
