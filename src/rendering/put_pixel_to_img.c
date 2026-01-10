/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:08:48 by lucorrei          #+#    #+#             */
/*   Updated: 2026/01/06 11:39:09 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rendering.h"

void	put_pixel_to_img(t_img *data, int x, int y, t_colour colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = ((unsigned int)colour.r << 16)
		+ ((unsigned int)colour.g << 8)
		+ (unsigned int)colour.b;
}
