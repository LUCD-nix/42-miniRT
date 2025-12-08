/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transp3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:23:50 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/04 17:23:51 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mat3.h"

inline t_mat3	transp3(t_mat3 m)
{
	t_mat3	res;

	res.rows[0] = (t_vec3) {m.rows[0].x, m.rows[1].x, m.rows[2].x};
	res.rows[1] = (t_vec3) {m.rows[0].y, m.rows[1].y, m.rows[2].y};
	res.rows[2] = (t_vec3) {m.rows[0].z, m.rows[1].z, m.rows[2].z};
	return (res);
}

