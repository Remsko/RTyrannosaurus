/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:42:39 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/03 12:58:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "rt.h"

typedef struct s_vector
{
	double x;
	double y;
	double z;
} t_vector;

typedef struct s_color
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
} t_color;

typedef struct s_object_type
{
	unsigned char sphere : 1;
	unsigned char plan : 1;
	unsigned char cylinder : 1;
	unsigned char cone : 1;
	unsigned char fill : 4;
} t_object_type;

typedef struct s_options
{
	t_bool exit : 1;
	t_bool draw : 1;
	t_bool fill : 6;
} t_options;

#endif