/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:01:51 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/11 15:45:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cut_line(char **pos, char **line)
{
	char *n_pos;

	if ((n_pos = ft_strchr(*pos, (int)'\n')))
	{
		*line = ft_strsub(*pos, 0, n_pos - *pos);
		ft_memmove(*pos, n_pos + 1, ft_strlen(n_pos));
		n_pos = NULL;
		return (1);
	}
	return (0);
}

static int	read_line(const int fd, char **pos, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = NULL;
		if (*pos)
		{
			tmp = ft_strdup(*pos);
			ft_strdel(*(&pos));
			*pos = ft_strjoin(tmp, buf);
			ft_strdel(&tmp);
		}
		else
			*pos = ft_strdup(buf);
		if (cut_line(pos, line))
			return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*pos;
	int			ret;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (pos && cut_line(&pos, line))
		return (1);
	if ((ret = read_line(fd, &pos, line)) != 0)
		return (ret);
	if (pos == NULL || pos[0] == '\0')
		return (0);
	*line = pos;
	pos = NULL;
	return (1);
}
