/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:27:04 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/13 21:58:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	sdl_destroy(t_visu *v)
{
	SDL_DestroyTexture(v->texture);
	SDL_DestroyRenderer(v->renderer);
	SDL_DestroyWindow(v->window);
	SDL_Quit();
}
