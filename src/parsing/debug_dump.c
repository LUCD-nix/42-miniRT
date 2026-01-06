#include <stdio.h>
#include "parsing.h"

static void print_vec3(const char *name, t_vec3 v)
{
	printf("%s: (%.3f, %.3f, %.3f)\n", name, v.x, v.y, v.z);
}

static void print_color(const char *name, t_colour c)
{
	printf("%s: (%d, %d, %d)\n", name, c.r, c.g, c.b);
}

void dump_scene(t_scene *s)
{
	printf("=== SCENE DUMP ===\n");

	printf("has_ambient=%d has_camera=%d has_light=%d\n",
		s->has_ambient, s->has_camera, s->has_light);

	printf("[AMBIENT]\n");
	printf("ratio=%.3f\n", s->ambient.ratio);
	print_color("color", s->ambient.color);

	printf("[CAMERA]\n");
	print_vec3("pos", s->camera.position);
	print_vec3("dir", s->camera.orientation);
	printf("fov=%f\n", s->camera.fov);

	printf("[LIGHT]\n");
	print_vec3("pos", s->light.position);
	printf("brightness=%.3f\n", s->light.brightness);
	print_color("color", s->light.color);

	// Si tu as de quoi compter tes objets dans t_shapes, ajoute ici un comptage
	printf("=== END DUMP ===\n");
}
