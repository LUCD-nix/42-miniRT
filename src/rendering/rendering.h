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
# define BACKGROUND ((t_colour){0, 0, 0, 0})
# define SHADOW_DIST_MIN 0.01f
# define SHADOW_I_MIN .0001f
# define SHADOW_DIST_MAX 100.f

typedef struct s_camera
{
	t_vec3	camera_pos;
	t_vec3	screen_plane;
	// unit screen up
	t_vec3	u_3;
	// unit screen left
	t_vec3	v_3;
}	t_camera;

typedef struct s_soft_shadows
{
	t_vec3	direction;
	float	intensity;
	float	previous;
	float	walk;
	float	delta;
	float	y;
	float	d;
	float	normal;
}	t_soft_shadows;

void		put_pixel_to_img(t_img *data, int x, int y, t_colour colour);
void		fast_render(t_shapes *objs, t_camera *cam, t_img *data);
void		full_render(t_shapes *objs, t_camera *cam, t_img *data);
t_cdist		scene(t_vec3 point, t_shapes *objs);
t_colour	apply_lights(t_shapes *objs, t_vec3 ray, t_cdist colour_dist);
t_vec3		get_uv(size_t px, size_t py, t_camera *cam);
t_vec3		get_normal(t_vec3 point, t_shapes *objs);
t_camera	camera_setup(t_vec3 position, t_vec3 view_dir, float h_fov);
t_colour	raymarch(t_vec3 origin, t_vec3 direction, t_shapes *objs);
float		soft_shadow(t_point_light light, t_shapes *objs, t_vec3 point);

#endif // RENDERING_H
