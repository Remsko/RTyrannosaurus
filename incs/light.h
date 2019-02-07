/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:07:12 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/07 11:32:19 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "color.h"
#include "vector.h"

/*
** Light type list aka index for *f[]
*/

typedef enum    e_light_type
{
    POINT = 0,
    DIRECTIONAL = 1,
    PARALLEL = 2,
    LIGHT_MAX,
}   t_light_type;


/*
** Data-structure with light as a generic entity
*/

typedef struct s_light
{
    void    *spec;
    t_color color;
    double intensity;
    t_light_type type;
} t_light;

/*
** All light structures
*/

typedef struct s_point
{
    t_vector source;
} t_point;

typedef struct s_directional
{
    t_vector source;
    t_vector direction;
} t_directional;

typedef struct s_parallel
{
    t_vector source;
    t_vector normal;
} t_parallel;

#endif