/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:36:31 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 13:07:24 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "ray.h"
# include "vector.h"

/*
** Object type list aka index for *f[]
*/

typedef enum	e_object_type
{
	SPHERE = 0,
	PLANE = 1,
	CYLINDER = 2,
	CONE = 3,
    OBJECT_MAX,
}				t_object_type;

/*
** Generic structure for all object type
*/

typedef struct	s_object
{
    void    *spec;
    //t_mater   mater;
    t_object_type type;
}				t_object;

/* 
** All object structures
** Describe object in space
*/

typedef struct	s_sphere
{
    t_vector    center;
    t_vector    rot;
    double      radius;
}               t_sphere;

typedef struct	s_cylinder
{
    t_vector    center;
    t_vector    rot;
    double      radius;
}				t_cylinder;

typedef struct	s_cone
{
    t_vector    center;
    t_vector    rot;
    double      radius;
}               t_cone;

typedef struct	s_plane
{
    t_vector    center;
    t_vector    normal;
    t_vector    rot;
}				t_plane;

int				solver_quadratic(const double a, const double b, const double c,
		double *t);

int				intersection_cone(t_ray const ray, void const *obj,
		double *t);
int				intersection_cylinder(t_ray const ray, void const *obj,
		double *t);
int				intersection_plane(t_ray const ray, void const *obj,
		double *t);
int				intersection_sphere(t_ray const ray, void const *obj,
		double *t);
int				get_inter(t_ray const ray, t_object const *obj, double *t);

t_vector	normal_cone(void const *obj, t_vector const ray_dir,
		t_vector const hit_pos);
t_vector	normal_cylinder(void const *obj, t_vector const ray_dir,
		t_vector const hit_pos);
t_vector	normal_plane(void const *obj, t_vector const ray_dir,
		t_vector const hit_pos);
t_vector	normal_sphere(void const *obj, t_vector const ray_dir,
		t_vector const hit_pos);
t_vector	get_normal(t_object const *obj, t_vector const ray_dir,
		t_vector const hit_pos);
#endif
