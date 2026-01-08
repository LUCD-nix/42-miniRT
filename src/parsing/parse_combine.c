/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_combine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:50:39 by hlongin           #+#    #+#             */
/*   Updated: 2026/01/08 12:31:13 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_combine_fn	get_smooth_func(char c)
{
	if (c == '+')
		return (&op_smooth_union);
	if (c == '-')
		return (&op_smooth_substraction);
	if (c == 'x')
		return (&op_smooth_intersection);
	return (NULL);
}

t_combine_fn	get_combine_func(char c)
{
	if (c == '+')
		return (&op_union);
	if (c == '-')
		return (&op_substraction);
	if (c == 'x')
		return (&op_intersection);
	if (c == '^')
		return (&op_xor);
	return (NULL);
}

static int	parse_smooth_combine(char *str, t_combine_op *op)
{
	double	k;

	op->func = get_smooth_func(str[1]);
	if (!op->func)
		return (0);
	if (str[2] != ':')
		return (0);
	if (!ft_atof_safe(str + 3, &k))
		return (0);
	op->smoothing = (float)k;
	return (1);
}

int	parse_combine(char *str, t_combine_op *op)
{
	op->smoothing = 0.0f;
	op->func = &op_union;
	if (!str)
		return (1);
	if (str[0] == 's')
		return (parse_smooth_combine(str, op));
	if (str[0] && (str[1] == '\0' || str[1] == '\n'))
	{
		op->func = get_combine_func(str[0]);
		if (!op->func)
			return (0);
		return (1);
	}
	return (0);
}
