/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:34:45 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/07 15:51:58 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

#include <stdbool.h>

#include "ray.h"
#include "object.h"

t_object *hit(double *t, t_ray *ray, t_object *objects, int n_object);

int	intersection_spec(const t_ray *ray, const t_object *object, double *t);

int intersection_sphere(const t_ray *ray, const void *object, double *t);

int intersection_plane(const t_ray *ray, const void *object, double *t);

int intersection_cone(const t_ray *ray, const void *object, double *t);

int intersection_cylinder(const t_ray *ray, const void *object, double *t);


#endif