/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:36:31 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/24 17:30:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "vector.h"

/*
** Object type list aka index for *f[]
*/

typedef enum			e_object_type
{
	SPHERE = 0,
	PLANE = 1,
	CYLINDER = 2,
	CONE = 3,
    OBJECT_MAX,
} t_object_type;

/*
** Generic structure for all object type
*/

typedef struct  s_object
{
    void    *spec;
    //t_mater   mater;
    t_object_type type;
} t_object;

/* 
** All object structures
** Describe object in space
*/

typedef struct  s_sphere
{
    t_vector    center;
    double      radius;
}               t_sphere;

typedef struct  s_cylinder
{
    t_vector    center;
    t_vector    rot;
    double      radius;
}               t_cylinder;

typedef struct  s_cone
{
    t_vector    center;
    t_vector    rot;
    double      radius;
}               t_cone;

typedef struct   s_plane
{
    t_vector    center;
    t_vector    normal;
}               t_plane;

#endif