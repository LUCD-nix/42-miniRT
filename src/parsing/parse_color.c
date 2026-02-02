/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:28:41 by hlongin           #+#    #+#             */
/*   Updated: 2026/01/15 14:11:24 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_color(char *str, t_colour *color)
{
	char	**rgb;
	double	r;
	double	g;
	double	b;
	int		success;

	rgb = ft_split(str, ',');
	success = 1;
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (printf("Error\nColour: missing or invalid tokens\n"), 0);
	else if (!ft_atof_safe(rgb[0], &r))
		success = 0;
	else if (!ft_atof_safe(rgb[1], &g))
		success = 0;
	else if (!ft_atof_safe(rgb[2], &b))
		success = 0;
	if (success && (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255))
		success = 0;
	if (!success)
		return (printf("Error\nColour: invalid tokens\n"), 0);
	*color = (t_colour){0xFF, (int)r, (int)g, (int)b};
	return (free_split(rgb), success);
}
