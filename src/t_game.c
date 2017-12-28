/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:43 by irhett            #+#    #+#             */
/*   Updated: 2017/12/27 16:09:43 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_game(t_game *g)
{
	if (g)
	{
		/* delete data */
		free(g);
	}
}

t_game	*new_game(void /* args */)
{
	t_game	*g;

	g = (t_game *)malloc(sizeof(t_game));
	if (!g)
		return (NULL);
	/* args */
	return (g);
}
