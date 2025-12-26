/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:33:38 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/12 17:33:38 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RENDERING_H
# define RENDERING_H
# include "../vec3/vec3.h"
# include "../mat3/mat3.h"
# include "../shapes/shapes.h"
# include "../window/window.h"
# include "../lighting/lighting.h"
# define MAX_STEPS 100
# define SURFACE_DIST 0.00001f
# define EPS_NORMAL 0.001f
# define SCREEN_LEN_X 1.0f

typedef struct s_camera
{
	t_vec3	camera_pos;
	t_vec3	screen_plane;
	// unit screen up
	t_vec3	u_3;
	// unit screen left
	t_vec3	v_3;
}	t_camera;



t_cdist		scene(t_vec3 point, t_shapes *objs);
t_vec3		get_uv(size_t px, size_t py, t_camera screen);
t_vec3		get_normal(t_vec3 point, t_shapes *objs);
t_camera	camera_setup(t_vec3 position, t_vec3 view_dir, float h_fov);
t_colour	raymarch(t_vec3 origin, t_vec3 direction, t_shapes *objs);
float	soft_shadow(t_point_light light, t_shapes *objs, t_vec3 point);

#endif // RENDERING_H
