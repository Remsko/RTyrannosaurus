/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nerf_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:06:23 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 00:11:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    nerf_double(double *d, double min, double max, double wanted)
{
    if (*d > max)
        *d = wanted;
    if (*d < min)
        *d = wanted;
}