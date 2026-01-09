#include "rendering.h"

void	put_pixel_to_img(t_img *data, int x, int y, t_colour colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = ((unsigned int)colour.r << 16)
		+ ((unsigned int)colour.g << 8)
		+ (unsigned int)colour.b;
}
