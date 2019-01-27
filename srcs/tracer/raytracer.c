/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:07:03 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 21:46:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "visu.h"
#include "color.h"

static void pixel_put(t_visu *v, t_color *c, int x, int y)
{
    SDL_SetRenderDrawColor(v->renderer, color->r, color->g, color->b, 255);
    SDL_RenderDrawPoint(v->renderer, x, y);
}

static double viewplane_x(int width, int column, int x, int samples)
{
    return (x - width / 2.0 + (column + 0.5) / samples);
}

static double viewplane_y(int height, row, y, samples)
{
    return (height / 2 - y + (row + 0.5) / samples);
}

/*
    public Ray createRay(Point2D point)
	{
		Ray ray = new Ray();
		
		ray.origin = Main.camera.position;
		
		ray.direction.x = point.x;
		ray.direction.y = point.y;
		ray.direction.z = Main.camera.distance;
		
		Main.rotation.rotate(ray.direction, Main.camera.rotation);
		ray.direction.normalize();
		return (ray);
    }
*/

static t_ray new_ray(t_camera *camera, double viewplane_x, double viewplane_y)
{
    t_ray ray;

    ray.origin = camera->position;
    ray.direction.x = viewplane_x;
    ray.direction.y = viewplane_y;
    ray.direction.z = camera->distance_from_viewplane;
    //ray.direction = vector_rotate3(ray.direction, camera->rotation);
    vector_normalize(&ray.direction);
    return (ray);
}

static void pixel_color(t_scene *scene, t_color *color, int x, int y)
{
    t_ray ray;
    int samples;
    int row;
    int column;

    ft_bzero((void *)color, sizeof(t_color));
    samples = scene->config->anti_aliasing;
    row = 0;
    while (row < samples)
    {
        column = 0;
        while (column < samples)
        {
            ray = new_ray(
                scene->camera,
                viewplane_x(scene->config->viewplane.width, column, x, samples);
                viewplane_y(scene->config->viewplane.height, row, y, samples);
            );
            color_add(color, throw_ray(scene, ray));
            ++column;
        }
        ++row;
    }
    color_divide_const(color, (double)(samples * samples));
    return (color);
}

void    raytracer(t_scene *scene, t_visu *visu)
{
    t_color color;
    int width;
    int height;
    int x;
    int y;

    width = v->screen.width;
    height = v->screen.height;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            pixel_color(scene, &color);
            pixel_put(visu, &color, x, y);
            ++x;
        }
        ++y;
    }
}