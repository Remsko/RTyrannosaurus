/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:25:08 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 16:33:58 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"
#include "parser.h"
//#include "visu.h"

void usage(char *bin)
{
	ft_putstr("usage: ");
	ft_putstr(bin);
	ft_putstr("<scene file>\n");
}

int	main(int ac, char **av)
{
	t_env	e;
	//t_visu	v;

	ft_bzero(&e, sizeof(t_env));
	//v.screen.width = WIN_W;
	//v.screen.height = WIN_H;
	if (ac == 2)
	{
		if ((e.scene = parser_file(av[1])) == NULL)
			return (1);
		//sdl_init(&v);
		//sdl_loop(&e, &v);
		//sdl_destroy(&v);
	}
	else
		usage(av[0]);
	return (0);
}
