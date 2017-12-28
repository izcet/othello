/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:43 by irhett            #+#    #+#             */
/*   Updated: 2017/12/28 00:24:25 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_game(t_game *g)
{
	unsigned int	i;

	if (g)
	{
		if (g->turn)
		{
			i = 0;
			while (i < g->maximum)
				del_turn(g->turn[i]);
			free(g->turn);
		}
		del_player(g->black);
		del_player(g->white);
		free(g);
	}
}

t_game	*new_game(unsigned char size)
{
	t_game			*g;
	unsigned int	i;

	g = (t_game *)malloc(sizeof(t_game));
	if (!g)
		return (game_error(NULL, "new_game malloc() of g"));
	
	g->size = size;
	g->maximum = ((size * size) * 1.5);
	g->turn_number = 0;
	if (make_players(t_game *g))
		return (game_error(g, "new_game make_players()"));
	
	g->turn = (t_turn **)malloc(sizeof(t_turn *) * maximum);
	if (!g->turn)
		return (game_error(g, "new_game malloc() of g->turn"));

	// TODO make this into a function in case boundaries need to be extended
	i = 0;
	while (i < maximum)
	{
		g->turn[i] = new_turn(/*TODO*/);
		// :TODO
		if (!g->turn[i])
		{
			del_game(g);
			return (game_error(NULL, "new_game malloc() of g->turn[i]"));
		}
		i++;
	}
	return (g);
}
