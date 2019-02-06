/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:07:03 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/06 10:08:47 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "scene.h"
#include "visu.h"
#include "color.h"
#include "vector.h"
#include "tracer.h"

#include "libft.h"


double viewplane_x(int width, int column, int x, int samples)
{
    return (x - width / 2.0 + (column + 0.5) / samples);
}

double viewplane_y(int height, int row, int y, int samples)
{
    return (height / 2 - y + (row + 0.5) / samples);
}

void new_ray(const t_camera *camera, t_ray *ray, const double viewplane_x, const double viewplane_y)
{
    ft_bzero((void *)ray, sizeof(t_ray));
    ray->origin = camera->position;
    ray->direction.x = viewplane_x;
    ray->direction.y = viewplane_y;
    ray->direction.z = camera->distance;
    vector_rotate(&ray->direction, &camera->rotation);
    vector_normalize(&ray->direction);
}

void pixel_color(t_scene *scene, t_color *color, int x, int y)
{
    t_viewplane *viewplane;
    t_ray ray;
    int samples;
    int row;
    int column;


    viewplane = &scene->config->viewplane;
    samples = scene->config->anti_aliasing;
    row = 0;
    while (row < samples)
    {
        column = 0;
        while (column < samples)
        {
            new_ray(
                scene->camera,
                &ray,
                viewplane_x(viewplane->width, column, x, samples),
                viewplane_y(viewplane->height, row, y, samples)
            );
            color_add(color, throw_ray(scene, &ray));
            ++column;
        }
        ++row;
    }
    color_divide_const(color, (const double)(samples * samples));
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
            pixel_color(scene, &color, x, y);
            sdl_pixel(visu, &color, x, y);
            ++x;
        }
        ++y;
    }
}