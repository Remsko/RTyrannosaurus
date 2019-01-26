/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:01:24 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 17:37:44 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "rt.h"
#include "json_parser.h"

t_scene *parser_file(char *path);

t_scene *parser_scene(t_json_object *json);

t_camera *parser_camera(t_json_value *value);

t_vector parser_vector(t_json_value *value);

double parser_double(t_json_value *value);

double value_to_double(void *ptr, t_json_value_type type);

bool value_exist(t_json_value *value);

#endif