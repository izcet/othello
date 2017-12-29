/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:44 by irhett            #+#    #+#             */
/*   Updated: 2017/12/28 21:19:25 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_world(t_world *w)
{
	if (w)
	{
		del_game(w->current);
		free(w);
	}
}

t_world	*new_world(unsigned char size)
{
	t_world	*w;

	w = (t_world *)malloc(sizeof(t_world));
	if (!w)
		return (NULL);
	ft_bzero(w, sizeof(t_world));
	w->board_size = size;
	w->current = new_game(size);
	return (w);
}
