/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:46:03 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/13 21:30:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/*
** Color structure
*/

typedef struct s_color
{
    double r;
    double g;
    double b;
} t_color;

/*
** Color add variations
** in color_add.c
*/

void color_add(t_color *target, t_color *amount);
void color_add_const(t_color *target, const double amount);
t_color color_add_ret(t_color *color, t_color *amount);
t_color color_add_const_ret(t_color *color, const double amount);

/*
** Color divide variations
** in color_divide.c
*/

void color_divide(t_color *target, t_color *amount);
void color_divide_const(t_color *target, const double amount);
t_color color_divide_ret(t_color *color, t_color *amount);
t_color color_divide_const_ret(t_color *color, const double amount);

/*
** Color multiply variations
** in color_multiply.c
*/

void color_multiply(t_color *target, t_color *amount);
void color_multiply_const(t_color *target, const double amount);
t_color color_multiply_ret(t_color *color, t_color *amount);
t_color color_multiply_const_ret(t_color *color, const double amount);

/*
** Color range modifications for rgb pixel display and Phong Shading calculations
** in color_to_range.c
*/

void color_to_range_0_255(t_color *color);
void color_to_range_0_1(t_color *color);

/*
** Color nerfs to avoid color overflows
** in color_to_max.c
*/

void color_to_max_255(t_color *color);
void color_to_max_1(t_color *color);

#endif