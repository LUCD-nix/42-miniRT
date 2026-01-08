/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:08:44 by hlongin           #+#    #+#             */
/*   Updated: 2026/01/08 11:59:18 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
