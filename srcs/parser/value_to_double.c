/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_to_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:27:50 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 17:42:55 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"

double value_to_double(void *ptr, t_json_value_type type)
{
    if (type == integer)
        return ((double)*(int *)ptr);
    else if (type == number)
        return ((double)*(double *)ptr);
    return (0.0);
}