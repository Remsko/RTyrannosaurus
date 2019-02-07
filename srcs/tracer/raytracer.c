/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:07:03 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/07 21:25:11 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "scene.h"
#include "visu.h"
#include "color.h"
#include "vector.h"
#include "tracer.h"

#include "libft.h"

static void pixel_color(t_scene *scene, t_screen *screen, t_pixel *pixel, t_color *color)
{
    t_ray *ray;
    t_position position;
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
            position = regular_sample(screen, pixel, row, column, samples);
            if ((ray = new_camera_ray(scene->camera, &position)) != NULL)
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
    t_pixel pixel;

    screen = &visu->screen;
    pixel.y = 0;
    while (pixel.y < screen->height)
    {
        pixel.x = 0;
        while (pixel.x < screen->width)
        {
            ft_bzero((void *)&color, sizeof(t_color));
            pixel_color(scene, screen, &pixel, &color);
            sdl_pixel(visu, &pixel, &color);
            ++pixel.x;
        }
        ++pixel.y;
    }
}