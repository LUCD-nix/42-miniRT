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

static inline t_vec3	get_uv(size_t px, size_t py)
{
	// FIXME : very simple impl, will need to change for setting view dir etc
	float	u = ((float) px / SCREEN_X - 0.5)  * (16.f / 9.f);
	float	v = (float) py / SCREEN_Y - 0.5;
	return (norm3((t_vec3){1, -v, u}));
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
	objs.n_shapes = 2;
	objs.shapes[0] = (union u_shape)(struct s_cylinder){
		.alignment = rot_mat3(M_PI_2, 0.f, 0.f),
		.position = (t_vec3) {3.f, 0.f, 0.f},
		.radius = 1.f,
		.height = 5.f
	};
	objs.sdfs[0] = &cylinder_sdf;

	// neg_sphere
	objs.shapes[1] = (union u_shape)(struct s_sphere){
		.position = (t_vec3){3.0f, 1.0f, 0.f},
		.radius = .5f
	};
	objs.sdfs[1] = &sphere_sdf;
	objs.smoothing[1] = 0.5f;
	objs.combine[1] = &op_smooth_substraction;

	clock_t start = clock();
	for (size_t i = 0; i < SCREEN_Y; i++)
	{
		for (size_t j = 0; j < SCREEN_X; j++)
		{
			t_vec3 rd = get_uv(j, i);
			unsigned int colour =
				raymarch((t_vec3){0.0f, 0.0f, 0.0f}, rd, &objs);
			put_pixel_to_img(&data, j, i, colour);
		}
	}
	clock_t end = clock();
	double render_time_s = (double)(end - start) / CLOCKS_PER_SEC;
	printf("finished rendering in %lf seconds\n", render_time_s);
	mlx_put_image_to_window(mlx, window, data.img, 0, 0);
	mlx_loop(mlx);
}
