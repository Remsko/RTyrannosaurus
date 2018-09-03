/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_multiply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:07:21 by rpinoit           #+#    #+#             */
/*   Updated: 2018/09/03 16:07:45 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void    color_multiply(t_color target, t_color amount)
{
    target.r *= amount.r;
    target.g *= amount.g;
    target.b *= amount.b;
}