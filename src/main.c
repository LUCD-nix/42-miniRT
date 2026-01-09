/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2026/01/06 23:53:33 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define	M_PI 3.14159265358979323846

#include "lighting/lighting.h"
#include "vec3/vec3.h"
#include "vec2/vec2.h"
#include "mat3/mat3.h"
#include "shapes/shapes.h"
#include "rendering/rendering.h"
#include "parsing/parsing.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "window/window.h"
#include "keyboard/keyboard.h"

static void	setup_lights(t_scene *parsed, t_shapes *objs)
{
	objs->ambient = (t_ambient_light){
		.direction = (t_vec3){0.f, -1.f, 0.f},
		.intensity = parsed->ambient.ratio,
		.colour = parsed->ambient.color
	};
	objs->point = (t_point_light){
		.position = parsed->light.position,
		.radius = 0.1f,
		.intensity = parsed->light.brightness,
		.colour = parsed->light.color
	};
	printf("light pos: { %f, %f, %f }\n",
		parsed->light.position.x,
		parsed->light.position.y,
		parsed->light.position.z);
	printf("light intensity: %f\n", parsed->light.brightness);
}

static t_camera	setup_camera(t_scene *parsed)
{
	float	fov_rad;

	fov_rad = parsed->camera.fov * M_PI / 180.0;
	return (camera_setup(
		parsed->camera.position,
		parsed->camera.orientation,
		fov_rad
	));
}

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*window;
	t_img		data;
	t_scene		parsed;
	t_camera	cam;
	t_scene_lucas		scene;
	clock_t		start;
	clock_t		end;

	if (argc != 2)
		return (printf("Usage: %s <scene.rt>\n", argv[0]), 1);
	
	if (!parse_scene(argv[1], &parsed))
		return (1);
	init_window(&mlx, &window, &data);
	setup_lights(&parsed, &parsed.shapes);
	cam = setup_camera(&parsed);
	printf("Camera pos: { %f, %f, %f }\n",
		cam.camera_pos.x, cam.camera_pos.y, cam.camera_pos.z);
	printf("Screen plane: { %f, %f, %f }\n",
		cam.screen_plane.x, cam.screen_plane.y, cam.screen_plane.z);
	scene = (t_scene_lucas){
		.objs = &parsed.shapes,
		.cam = &cam,
		.mlx = mlx,
		.mlx_window = window,
		.img = &data
	};
	register_mlx_callbacks(window, &scene);
	start = clock();
	full_render(&parsed.shapes, &cam, &data);
	end = clock();
	printf("Rendered in %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
	mlx_put_image_to_window(mlx, window, data.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
