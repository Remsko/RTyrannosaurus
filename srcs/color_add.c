/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:03:48 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/04 18:00:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void    color_add(t_color *target, t_color *amount)
{
    target->r += amount->r;
    target->g += amount->g;
    target->b += amount->b;
}