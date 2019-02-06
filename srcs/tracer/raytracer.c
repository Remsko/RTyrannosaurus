/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:07:03 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 13:35:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "scene.h"
#include "visu.h"
#include "color.h"
#include "vector.h"
#include "tracer.h"

#include "libft.h"

static double regular_sample_x(int width, int column, int x, int samples)
{
    return (x - width * 0.5 + (column + PIXEL_CENTER) / samples);
}

static double regular_sample_y(int height, int row, int y, int samples)
{
    return (height * 0.5 - y + (row + PIXEL_CENTER) / samples);
}

static void pixel_color(t_scene *scene, t_color *color, t_screen *screen, int x, int y)
{
    t_ray *ray;
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
            ray = new_ray(
                scene->camera,
                regular_sample_x(screen->width, column, x, samples),
                regular_sample_y(screen->height, row, y, samples)
            );
            if (ray != NULL)
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
    t_color color;
    int width;
    int height;
    int x;
    int y;

    width = visu->screen.width;
    height = visu->screen.height;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            ft_bzero((void *)&color, sizeof(t_color));
            pixel_color(scene, &color, &visu->screen, x, y);
            sdl_pixel(visu, &color, x, y);
            ++x;
        }
        ++y;
    }
}