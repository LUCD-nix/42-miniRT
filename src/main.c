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
#include "vec3/vec3.h"
#include "mat3/mat3.h"
#include "shapes/shapes.h"
#include "rendering/rendering.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <time.h>
#include "window/window.h"

static inline void	put_pixel_to_img(t_img *data, int x, int y, int color)
{
	// TODO : consider manual inlining
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void			*mlx;
	void			*window;
	t_img			data;
	static t_shapes	objs;
	
	// Init window exits in case of problem
	init_window(&mlx, &window, &data);

	// Cylinder
	objs.n_shapes = 3;
	objs.shapes[0] = (union u_shape)(struct s_cylinder){
		.alignment = rot_mat3(M_PI_2, 0.f, 0.f),
		.position = (t_vec3) {3.f, -1.f, 0.f},
		.radius = 1.f,
		.height = 5.f
	};
	objs.sdfs[0] = &cylinder_sdf;
	objs.colours[0] = 0xFF00FF;

	// neg_sphere
	objs.shapes[1] = (union u_shape)(struct s_sphere){
		.position = (t_vec3){3.0f, 0.0f, 0.f},
		.radius = .5f
	};
	objs.sdfs[1] = &sphere_sdf;
	objs.smoothing[1] = 0.1f;
	objs.combine[1] = &op_smooth_substraction;
	objs.colours[1] = 0xFFFFFFFF;

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
	objs.colours[2] = 0xFF00FFFF;

#define MRT_SQRT1_3 0.57735026919f

	t_camera cam = camera_setup((t_vec3){-1.f, 1.f, 1.f },
							 norm3((t_vec3){4, -1.f, -1.f}),
							 M_PI_2);
	printf("pointer to center of screen : { %f, %f, %f }\n", cam.screen_plane.x, cam.screen_plane.y, cam.screen_plane.z);
	printf("normalized u_dir: { %f, %f, %f }\n", cam.u_3.x, cam.u_3.y, cam.u_3.z);
	printf("normalized v_dir: { %f, %f, %f }\n", cam.v_3.x, cam.v_3.y, cam.v_3.z);
	clock_t start = clock();
	for (size_t i = 0; i < SCREEN_Y; i++)
	{
		for (size_t j = 0; j < SCREEN_X; j++)
		{
			t_vec3 rd = get_uv(j, i, cam);
			// printf("looking at : { %f, %f, %f }\n", rd.x, rd.y, rd.z);
			unsigned int colour =
				raymarch(cam.camera_pos, rd, &objs);
			put_pixel_to_img(&data, j, i, colour);
		}
	}
	clock_t end = clock();
	double render_time_s = (double)(end - start) / CLOCKS_PER_SEC;
	printf("finished rendering in %lf seconds\n", render_time_s);
	mlx_put_image_to_window(mlx, window, data.img, 0, 0);
	mlx_loop(mlx);
}
