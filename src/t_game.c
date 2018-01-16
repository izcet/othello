/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:43 by irhett            #+#    #+#             */
/*   Updated: 2018/01/15 17:46:06 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	del_game(t_game *g)
{
	int		i;

	if (g)
	{
		if (g->turn)
		{
			i = 0;
			while (i < g->turn_size)
				del_turn(g->turn[i], g->boardsize);
			free(g->turn);
		}
		del_player(g->black);
		del_player(g->white);
		free(g);
	}
}

t_turn	**make_turns(unsigned int num)
{
	t_turn			**t;

	t = (t_turn **)malloc(sizeof(t_turn *) * num);
	if (!t)
		return (game_error(NULL, "make_turns()"));
	return (t);
}


/*
 * copies the existing array of turns to a new one
 * adds new entries to the "extended" part of the array
 * on success, it updates (within the t_game struct)
 * 		- turn_size
 * 		- turn
 * on success, it returns the newly created turn variable
 * on failure, the t_game struct is left untouched, and NULL is returned
 */
t_turn	**extend_game(t_game *g)
{
	int		i;
	int		max;
	t_turn	**temp;

	max = g->turn_size * 2;
	temp = make_turns(max);
	if (!temp)
		return (game_error(NULL, "extend_game make_turns()"));
	i = 0;
	while (i < g->turn_size)
	{
		temp[i] = g->turn[i];
		i++;
	}
	while (i < max)
	{	
		temp[i] = new_turn(g->boardsize, g->turn[i - 1]->active->opponent);
		if (!temp[i++])
		{
			max = i;
			i = g->turn_size;
			while (i < max)
				del_turn(temp[i++], g->boardsize);
			return (game_error(temp, "extend_game new_turn()"));
		}
	}
	g->turn_size = max;
	free(g->turn);
	g->turn = temp;
	return (temp);
}

t_game	*new_game(unsigned char size)
{
	t_game	*g;
	int		i;

	g = (t_game *)malloc(sizeof(t_game));
	if (!g)
		return (game_error(NULL, "new_game malloc() of g"));
	ft_bzero(g, sizeof(t_game));
	g->boardsize = size;
	g->turn_size = ((size * size) * 1.5);
	if (make_players(g))
		return (game_error(g, "new_game make_players()"));
	g->turn = make_turns(g->turn_size);
	if (!g->turn)
		return (game_error(g, "new_game make_turns()"));

	i = 0;
	while (i < g->turn_size)
	{
		if (i % 2 == 0)
			g->turn[i] = new_turn(size, g->black);
		else
			g->turn[i] = new_turn(size, g->white);
		if (!g->turn[i])
		{
			del_game(g);
			return (game_error(NULL, "new_game malloc() of g->turn[i]"));
		}
		i++;
	}
	return (g);
}
