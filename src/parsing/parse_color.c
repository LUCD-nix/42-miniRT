/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:28:41 by hlongin           #+#    #+#             */
/*   Updated: 2026/01/06 23:56:29 by hlongin          ###   ########.fr       */
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
	if (success && (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255))
		success = 0;
	if (success)
		*color = (t_colour){0xFF, (int)r, (int)g, (int)b};
	return (free_split(rgb), success);
}
