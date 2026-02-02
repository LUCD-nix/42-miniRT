/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:08:44 by hlongin           #+#    #+#             */
/*   Updated: 2026/02/02 16:40:01 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <math.h>

int	parse_vec3(char *str, t_vec3 *vec)
{
	char	**coords;
	double	x;
	double	y;
	double	z;
	int		success;

	coords = ft_split(str, ',');
	if (!coords)
		return (0);
	success = 1;
	if (!coords[0] || !coords[1] || !coords[2] || coords[3])
		success = 0;
	else if (!ft_atof_safe(coords[0], &x))
		success = 0;
	else if (!ft_atof_safe(coords[1], &y))
		success = 0;
	else if (!ft_atof_safe(coords[2], &z))
		success = 0;
	if (success)
	{
		vec->x = (float)x;
		vec->y = (float)y;
		vec->z = (float)z;
	}
	return (free_split(coords), success);
}

int	parse_vecnorm(char *str, t_vec3 *vec)
{
	int	result;

	if (!parse_vec3(str, vec))
		return (0);
	result = fabsf(length3(*vec) - 1.f) < 0.01f;
	return (result);
}
