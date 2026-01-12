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
#include "parsing/parsing.h"
#include "../minilibx-linux/mlx.h"
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
			fov_rad));
}

int	main(int argc, char **argv)
{
	t_img					data;
	t_scene					parsed;
	t_camera				cam;
	static t_runtime	runtime = (t_runtime){0};

	if (argc != 2)
		return (printf("Usage: %s <scene.rt>\n", argv[0]), 1);
	if (!parse_scene(argv[1], &parsed))
		return (1);
	init_window(&runtime.mlx, &runtime.mlx_window, &data);
	setup_lights(&parsed, &parsed.shapes);
	cam = setup_camera(&parsed);
	runtime.objs = &parsed.shapes;
	runtime.cam = &cam;
	runtime.img = &data;
	register_mlx_callbacks(runtime.mlx_window, &runtime);
	full_render(&parsed.shapes, &cam, runtime.mlx_window, runtime.mlx);
	mlx_put_image_to_window(runtime.mlx, runtime.mlx_window, data.img, 0, 0);
	mlx_loop(runtime.mlx);
	return (0);
}
