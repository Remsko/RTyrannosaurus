/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:34:45 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/29 23:38:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

#include <stdbool.h>

#include "ray.h"
#include "object.h"

bool hit(t_object *objects, int n_object, t_ray ray);

int	intersection_spec(t_ray const ray, t_object const *object, double *t);

int intersection_sphere(t_ray const ray, void const *object, double *t);

int intersection_plane(t_ray const ray, void const *object, double *t);

int intersection_cone(t_ray const ray, void const *object, double *t);

int intersection_cylinder(t_ray const ray, void const *object, double *t);


#endif