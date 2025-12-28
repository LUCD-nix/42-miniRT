#include "rendering.h"

static inline void	put_pixel_to_img(t_img *data, int x, int y, t_colour colour)
{
	// TODO : This could be mlx_pixel_put for a more visual effect
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = ((unsigned int)colour.r << 16)
		+  ((unsigned int)colour.g << 8)
		+ (unsigned int)colour.b;
}

void	full_render(t_shapes objs, t_camera cam, t_img *data)
{
	size_t	i;
	size_t	j;

	i = -1;
	while ( ++i < SCREEN_Y)
	{
		j = -1;
		while ( ++j < SCREEN_X)
		{
			rd = get_uv(j, i, cam);
			temp = raymarch(cam.camera_pos, rd, &objs);
			put_pixel_to_img(data, j, i, temp);
		}
	}
}
