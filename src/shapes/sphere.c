/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:06:59 by lucorrei          #+#    #+#             */
/*   Updated: 2025/11/28 15:06:59 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "shapes.h"

inline t_cdist	sphere_sdf(t_vec3 p, union u_shape shape, unsigned int colour)
{
	// NOTE : this is not exactly as in the reference articles, might change
	// if performance is bad;

	return ((t_cdist){
		length3(diff3(p, shape.sphere.position)) - shape.sphere.radius,
		colour}
	);
}
