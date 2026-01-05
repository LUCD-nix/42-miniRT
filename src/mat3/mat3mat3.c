/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3mat3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:51:23 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/04 16:51:23 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat3.h"

t_mat3	mat3mat3(t_mat3 a, t_mat3 b)
{
	t_mat3	res;
	int		i;
	t_mat3	b_transp;

	b_transp = transp3(b);
	i = -1;
	while (++i < 3)
		res.rows[i] = mat3vec(a, b_transp.rows[i]);
	return (transp3(res));
}
