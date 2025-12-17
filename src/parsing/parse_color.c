/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:28:41 by hlongin           #+#    #+#             */
/*   Updated: 2025/12/17 17:35:58 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_color(char *str, unsigned int *color)
{
	char	**rgb;
	double	r;
	double	g;
	double	b;
	int		success;

	rgb = ft_split(str, ',');
	if (!rgb)
		return (0);
	success = 1;
	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		success = 0;
	else if (!ft_atof_safe(rgb[0], &r))
		success = 0;
	else if (!ft_atof_safe(rgb[1], &g))
		success = 0;
	else if (!ft_atof_safe(rgb[2], &b))
		success = 0;
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		success = 0;
	if (success)
		*color = (0xFF << 24) | ((int)r << 16) | ((int)g << 8) | (int)b;
	return (free_split(rgb), success);
}
