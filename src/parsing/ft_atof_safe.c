/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:13:19 by hlongin           #+#    #+#             */
/*   Updated: 2026/01/15 14:29:41 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	skip_spaces(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r')
		i++;
	return (i);
}

static int	parse_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static double	parse_integer(const char *str, int *i, int *has_digit)
{
	double	value;

	value = 0.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*has_digit = 1;
		value = value * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (value);
}

static double	parse_decimale(const char *str, int *i, int *has_digit)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			*has_digit = 1;
			fraction = fraction * 10.0 + (str[*i] - '0');
			divisor *= 10.0;
			(*i)++;
		}
	}
	return (fraction / divisor);
}

double	ft_atof_safe(const char *str, double *result)
{
	int		i;
	int		has_digit;
	int		sign;
	double	value;
	double	fraction;

	i = 0;
	has_digit = 0;
	i = skip_spaces(str, i);
	sign = parse_sign(str, &i);
	value = parse_integer(str, &i, &has_digit);
	fraction = parse_decimale(str, &i, &has_digit);
	i = skip_spaces(str, i);
	if (str[i] != '\0' || !has_digit)
		return (0);
	value = sign * (value + fraction);
	if (isinf(value) || isnan(value))
		return (0);
	*result = value;
	return (1);
}
