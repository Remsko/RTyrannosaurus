/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:23:56 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 01:25:17 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

/*
** 3D Vector structure
*/

typedef struct s_vector
{
    double x;
    double y;
    double z;
} t_vector;

/*
** Vector add variations
** in vector_add.c
*/

void vector_add(t_vector *a, t_vector const b);
void vector_add_const(t_vector *vector, const double amount);
t_vector vector_add_ret(t_vector const a, t_vector const b);
t_vector vector_add_const_ret(t_vector const vector, const double amount);

/*
** Vector multiply variations
** in vector_multiply.c
*/

void vector_multiply(t_vector *a, t_vector const b);
void vector_multiply_const(t_vector *vector, const double amount);
t_vector vector_multiply_ret(t_vector const a, t_vector const b);
t_vector vector_multiply_const_ret(t_vector const vector, const double amount);

/*
** Vector sub variations
** in vector_sub.c
*/

void vector_sub(t_vector *a, t_vector const b);
void vector_sub_const(t_vector *vector, const double amount);
t_vector vector_sub_ret(t_vector const a, t_vector const b);
t_vector vector_sub_const_ret(t_vector const vector, const double amount);

/*
** Vector divide variations
*/

void vector_divide(t_vector *a, t_vector const b);
void vector_divide_const(t_vector *vector, const double amount);
t_vector vector_divide_ret(t_vector const a, t_vector const b);
t_vector vector_divide_const_ret(t_vector const vector, const double amount);

/*
** Dot product calculation
** in vector_dot_product.c
*/

double vector_dot_product(t_vector const a, t_vector const b);

/*
** Vector magnitude calculation
*/

double vector_magnitude(t_vector const vector);

/*
** Vector normalization to reduce vector len to 1
*/

void vector_normalize(t_vector *vector);

/*
** Vector matrix rotation
*/

t_vector	vector_rotate_x(t_vector const a, const double rad);
t_vector	vector_rotate_y(t_vector const a, const double rad);
t_vector	vector_rotate_z(t_vector const a, const double rad);
t_vector	vector_rotate3(t_vector const a, t_vector const rad);

#endif
