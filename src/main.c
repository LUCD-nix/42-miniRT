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
#include "shapes/shapes.h"
#include "vec3/vec3.h"
#include "../minilibx-linux/mlx.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_STEPS 100
#define SURFACE_DIST 0.00001f
#define SCREEN_X 1920
#define SCREEN_Y 1080
// #define SCREEN_X 160
// #define SCREEN_Y 90

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

static inline t_vec3	get_normal(
							t_vec3 pos,
							float (*sdf)(t_vec3, t_shape),
							t_shape ball)
{
	t_vec3	normal;
	float	h;

	h = 0.01f;
	normal = (t_vec3){
		sdf(add3(pos, (t_vec3){h, 0, 0}), ball),
		sdf(add3(pos, (t_vec3){0, h, 0}), ball),
		sdf(add3(pos, (t_vec3){0, 0, h}), ball),
	};
	return (norm3(normal));
}

static inline void	put_pixel_to_img(t_img *data, int x, int y, int color)
{
	// TODO : consider manual inlining
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static inline unsigned int	raymarch(t_vec3 origin, t_vec3 direction)
{
	float	dS;
	t_vec3	tmp;
	t_vec3	normal;
	t_shape	ball;
	size_t	i;

	ball.position = (t_vec3){2.0f, 0.0f, 0.0f};
	ball.type = SPHERE;
	ball.sphere.radius = 1.f;
	dS = sphere_sdf(origin, ball);
	tmp = add3(origin, fmult3(direction, dS));
	i = -1;
	while (++i < MAX_STEPS)
	{
		dS = sphere_sdf(tmp, ball);
		if (fabsf(dS) < SURFACE_DIST)
			break ;
		tmp = add3(tmp, fmult3(direction, dS));
	}
	// background
	if (i == MAX_STEPS)
		return (0);
	printf("sphere:{ %f, %f, %f }\n", tmp.x, tmp.y, tmp.z);
	normal = get_normal(tmp, &sphere_sdf, ball);
	printf("normal:{ %f, %f, %f }\n", normal.x, normal.y, normal.z);
	float diffuse = fmaxf(
		dot3(normal, (t_vec3){0.f, 1.f, 0.f}),
		0.0f
	);
	unsigned int light = (int)(diffuse * 255);
	return ((light << 24) + (light << 16)+  (light << 8) + light);
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
	void	*mlx;
	void	*window;
	t_img	data;

	mlx = mlx_init();
	if (mlx == NULL)
		exit(EXIT_FAILURE);
	window = mlx_new_window(mlx, SCREEN_X, SCREEN_Y, "miniRT");
	if (window == NULL)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		exit(EXIT_FAILURE);
	}
	data.img = mlx_new_image(mlx, SCREEN_X, SCREEN_Y);
	if (data.img == NULL)
	{
		mlx_destroy_window(mlx, window);
		mlx_destroy_display(mlx);
		free(mlx);
		exit(EXIT_FAILURE);
	}
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
		&data.line_length, &data.endian);

	for (size_t i = 0; i < SCREEN_Y; i++)
	{
		for (size_t j = 0; j < SCREEN_X; j++)
		{
			t_vec3 rd = get_uv(j, i);
			unsigned int colour = raymarch((t_vec3){0.0f, 0.0f, 0.0f}, rd);
			put_pixel_to_img(&data, j, i, colour);
		}
	}
	mlx_put_image_to_window(mlx, window, data.img, 0, 0);
	mlx_loop(mlx);
}
