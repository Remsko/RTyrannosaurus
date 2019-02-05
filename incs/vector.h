/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:23:56 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/05 20:51:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

/*
** 3D Vector
*/

typedef struct	s_vector
{
    double x;
    double y;
    double z;
}				t_vector;

/*
** Vector add variations
** in vector_add.c
*/

void vector_add(t_vector *a, const t_vector *b);
void vector_add_const(t_vector *vector, const double amount);
t_vector vector_add_ret(const t_vector *a, const t_vector *b);
t_vector vector_add_const_ret(const t_vector *vector, const double amount);

/*
** Vector multiply variations
** in vector_multiply.c
*/

void vector_multiply(t_vector *a, t_vector b);
void vector_multiply_const(t_vector *vector, const double amount);
t_vector vector_multiply_ret(t_vector const *a, t_vector const *b);
t_vector vector_multiply_const_ret(t_vector const *vector, const double amount);

/*
** Vector sub variations
** in vector_sub.c
*/

void vector_sub(t_vector *a, const t_vector *b);
void vector_sub_const(t_vector *vector, const double amount);
t_vector vector_sub_ret(const t_vector *a, const t_vector *b);
t_vector vector_sub_const_ret(const t_vector *vector, const double amount);

/*
** Vector divide variations
** in vector_divide.c
*/

void vector_divide(t_vector *a, t_vector const *b);
void vector_divide_const(t_vector *vector, const double amount);
t_vector vector_divide_ret(const t_vector *a, const t_vector *b);
t_vector vector_divide_const_ret(const t_vector *vector, const double amount);

/*
** Dot product calculation
** in vector_dot_product.c
*/

double vector_dot_product(const t_vector *a, const t_vector *b);

/*
** Vector magnitude calculation
*/

double vector_magnitude(const t_vector *vector);

/*
** Vector normalization to reduce vector length to 1
*/

void		vector_normalize(t_vector *vector);
t_vector	vector_normalize_ret(const t_vector *vector);

/*
** Vector matrix rotation
*/

void	vector_rotate_x(t_vector *a, const double rad);
void	vector_rotate_y(t_vector *a, const double rad);
void	vector_rotate_z(t_vector *a, const double rad);
void	vector_rotate(t_vector *a, const t_vector *deg);
void	vector_unrotate(t_vector *a, const t_vector *deg);

#endif
