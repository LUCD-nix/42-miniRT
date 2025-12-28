/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2025/11/30 14:09:22 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "lighting/lighting.h"
#include "vec3/vec3.h"
#include "mat3/mat3.h"
#include "shapes/shapes.h"
#include "rendering/rendering.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <time.h>
#include "window/window.h"

static inline void	put_pixel_to_img(t_img *data, int x, int y, t_colour colour)
{
	// TODO : consider manual inlining
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = ((unsigned int)colour.r << 16)
		+  ((unsigned int)colour.g << 8)
		+ (unsigned int)colour.b;
}

int	main(void)
{
	void			*mlx;
	void			*window;
	t_img			data;
	static t_shapes	objs;

	// Init window exits in case of problem
	init_window(&mlx, &window, &data);

	objs.point = (t_point_light){
		.position = (t_vec3) {4.f, 4.f, 4.f},
		.radius = 10.f,
		.intensity = 0.5f,
		.colour = {0xFF, 0xFF, 0xFF, 0xFF}
	};
	objs.ambient = (t_ambient_light){
		.direction = (t_vec3) {0.f, -M_SQRT1_2, -M_SQRT1_2},
		.colour = (t_colour){0xFF, 0x8F, 0x0, 0xFF},
		.intensity = 0.5f
	};
	objs.n_shapes = 4;
	// Cylinder
	objs.shapes[0] = (union u_shape)(struct s_cylinder){
		.alignment = rot_mat3(M_PI_2, 0.f, 0.f),
		.position = (t_vec3) {3.f, -1.f, 0.f},
		.radius = 1.f,
		.height = 5.f
	};
	objs.sdfs[0] = &cylinder_sdf;
	objs.colours[0] = (t_colour){0, 0xee, 0xee, 0xee};

	// neg_sphere
	objs.shapes[1] = (union u_shape)(struct s_sphere){
		.position = (t_vec3){3.0f, 0.0f, 0.f},
		.radius = .5f
	};
	objs.sdfs[1] = &sphere_sdf;
	objs.smoothing[1] = 0.1f;
	objs.combine[1] = &op_smooth_substraction;
	objs.colours[1] = (t_colour){0xff, 0x00, 0xff, 0};

	// box
	objs.shapes[2] = (union u_shape)(struct s_box){
		.rotation = rot_mat3(M_PI_4, M_PI_4, 0.f),
		.position = (t_vec3) {3.f, 0.5f, 0.f},
		.lx = 1.f,
		.ly = 1.f,
		.lz = 1.f,
	};
	objs.sdfs[2] = &box_sdf;
	objs.smoothing[2] = 0.1f;
	objs.combine[2] = &op_smooth_union;
	objs.colours[2] = (t_colour){0, 0xff, 0x0, 0xff};

	//Plane
	objs.shapes[3] = (union u_shape)(struct s_plane){
		.height = -1.f,
		.normal = (t_vec3){0.f, 1.f, 0.f}
	};
	objs.sdfs[3] = &plane_sdf;
	objs.combine[3] = &op_union;
	objs.colours[3] = (t_colour){0, 0, 77, 64};

#define MRT_SQRT1_3 0.57735026919f

	t_camera cam = camera_setup((t_vec3){-1.f, 1.f, 1.f },
							 norm3((t_vec3){4, -1.f, -1.f}),
							 M_PI_2);
	printf("pointer to center of screen : { %f, %f, %f }\n",
		cam.screen_plane.x, cam.screen_plane.y, cam.screen_plane.z);
	printf("normalized u_dir: { %f, %f, %f }\n", cam.u_3.x, cam.u_3.y,
		cam.u_3.z);
	printf("normalized v_dir: { %f, %f, %f }\n", cam.v_3.x, cam.v_3.y,
		cam.v_3.z);
	clock_t start = clock();
	full_render(objs, cam, &data);
	clock_t end = clock();
	double render_time_s = (double)(end - start) / CLOCKS_PER_SEC;
	printf("finished rendering in %lf seconds\n", render_time_s);
	mlx_put_image_to_window(mlx, window, data.img, 0, 0);
	mlx_loop(mlx);
}
