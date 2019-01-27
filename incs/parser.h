/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:01:24 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/27 17:31:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "rt.h"
#include "json_parser.h"

t_scene *parser_file(char *path);

t_scene *parser_scene(t_json_object *json);

t_camera *parser_camera(t_json_value *value);

t_config *parser_config(t_json_value *value);

t_light *parser_lights(t_json_value *value);

t_object *parser_objects(t_json_value *value);

t_vector parser_vector(t_json_value *value);

t_object_type parser_object_type(t_json_value *value);

void *parser_object_spec(t_json_value *value, t_object_type type);

void *parser_sphere(t_json_object *o);

void *parser_plane(t_json_object *o);

void *parser_cylinder(t_json_object *o);

void *parser_cone(t_json_object *o);

double parser_double(t_json_value *value);

double value_to_double(void *ptr, t_json_value_type type);

bool value_exist(t_json_value *value);

void nerf_double(double *d, double min, double max);

void nerf_rotation(t_vector *rot);

void nerf_color(t_color *color);

#endif