/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:26:50 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 10:35:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

#include "libft.h"

#define WIN_W 1000
#define WIN_H 1000

/*
** Environment structure: Raytracer configurations
*/

typedef struct s_env
{
    void *config;
} t_env;

#endif
