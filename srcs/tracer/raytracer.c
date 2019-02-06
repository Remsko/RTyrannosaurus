/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:07:03 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 19:42:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "scene.h"
#include "visu.h"
#include "color.h"
#include "vector.h"
#include "tracer.h"

#include "libft.h"

static void pixel_color(t_scene *scene, t_color *color, t_screen *screen, int x, int y)
{
    t_ray *ray;
    t_pixel pixel;
    int samples;
    int row;
    int column;

    samples = scene->config->anti_aliasing;
    row = 0;
    while (row < samples)
    {
        column = 0;
        while (column < samples)
        {
            pixel = regular_sample(screen, row, column, x, y, samples);
            if ((ray = new_ray(scene->camera, &pixel)) != NULL)
                color_add(color, throw_ray(scene, ray));
            free(ray);
            ++column;
        }
        ++row;
    }
    color_divide_const(color, samples * samples);
}

void    raytracer(t_scene *scene, t_visu *visu)
{
    t_screen *screen;
    t_color color;
    int x;
    int y;

    screen = &visu->screen;
    width = screen->width;
    height = screen->height;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            ft_bzero((void *)&color, sizeof(t_color));
            pixel_color(scene, &color, screen, x, y);
            sdl_pixel(visu, &color, x, y);
            ++x;
        }
        ++y;
    }
}