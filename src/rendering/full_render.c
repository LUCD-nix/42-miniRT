#include "rendering.h"

void	full_render(t_shapes *objs, t_camera *cam, t_img *data)
{
	size_t		i;
	size_t		j;
	t_vec3		rd;
	t_colour	temp;

	i = -1;
	while (++i < SCREEN_Y)
	{
		j = -1;
		while (++j < SCREEN_X)
		{
			rd = get_uv(j, i, cam);
			temp = raymarch(cam->camera_pos, rd, objs);
			put_pixel_to_img(data, j, i, temp);
		}
	}
}
