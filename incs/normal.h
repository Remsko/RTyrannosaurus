/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:12:32 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/07 22:14:16 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
#define NORMAL_H

#include "vector.h"
#include "ray.h"
#include "object.h"

t_vector new_normal(t_object *object, t_ray *ray, t_vector *hit);

t_vector normal_cylinder(void *object, t_ray *ray, t_vector *hit);

t_vector normal_plane(void *object, t_ray *ray, t_vector *hit);

t_vector normal_sphere(void *object, t_ray *ray, t_vector *hit);

t_vector normal_cone(void *object, t_ray *ray, t_vector *hit);

#endif