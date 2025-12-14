/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:33:38 by lucorrei          #+#    #+#             */
/*   Updated: 2025/12/12 17:33:38 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RENDERING_H
# define RENDERING_H
# include "../vec3/vec3.h"
# include "../mat3/mat3.h"
# include "../shapes/shapes.h"
#define MAX_STEPS 100
#define SURFACE_DIST 0.00001f
#define EPS_NORMAL 0.001f

float				sdf(t_vec3 point, t_shapes *objs);
t_vec3				get_normal(t_vec3 point, t_shapes *objs);
unsigned int		raymarch(t_vec3 origin, t_vec3 direction, t_shapes *objs);

#endif // RENDERING_H
