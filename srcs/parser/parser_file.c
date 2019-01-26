/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:51:17 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 18:05:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

#include "json_parser.h"
#include "json_free.h"
#include "libft.h"

char    *read_file(int fd)
{
    char    buf[BUFF_SIZE + 1];
    char    *str;
    char    *tmp;
    int     ret;

    str = NULL;
    while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[ret] = '\0';
        if (str != NULL)
        {
            tmp = strdup(str);
            free(str);
            str = ft_strjoin(tmp, buf);
            free(tmp);
        }
        else
            str = ft_strdup(buf);
    }
    if (ret == -1)
        free(str);
    return (str);
}

t_scene *parser_file(char *path)
{
    t_json_value *json;
    t_scene *scene;
    char *file;
    int fd;

    scene = NULL;
    if ((fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    file = read_file(fd);
    json = json_parse(file);
    if (value_exist(json) && json->type == object)
        scene = parser_scene((t_json_object *)json->ptr);
    else
        scene = NULL;
    free(file);
    json_free_value(json);
    close(fd);
    return (scene);
}