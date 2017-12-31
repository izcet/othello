/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:43 by irhett            #+#    #+#             */
/*   Updated: 2017/12/30 17:33:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	del_game(t_game *g)
{
	unsigned int	i;

	if (g)
	{
		if (g->turn)
		{
			i = 0;
			while (i < g->num_turns)
				del_turn(g->turn[i]);
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
 * 		- num_turns
 * 		- turn
 * on success, it returns the newly created turn variable
 * on failure, the t_game struct is left untouched, and NULL is returned
 */
t_turn	**extend_game(t_game *g)
{
	unsigned int	i;
	unsigned int	max;
	t_turn			**temp;

	max = g->num_turns * 2;
	temp = make_turns(max);
	if (!temp)
		return (game_error(NULL, "extend_game make_turns()"));
	i = 0;
	while (i < g->num_turns)
	{
		temp[i] = g->turn[i];
		i++;
	}
	while (i < max)
	{
		temp[i] = new_turn(g->boardsize, i, g->turn[i - 1]->active->opponent);
		if (!temp[i++])
		{
			max = i;
			i = g->num_turns;
			while (i < max)
				del_turn(temp[i++]);
			return (game_error(temp, "extend_game new_turn()"));
		}
	}
	g->num_turns = max;
	free(g->turn);
	g->turn = temp;
	return (temp);
}

t_game	*new_game(unsigned char size)
{
	t_game			*g;
	unsigned int	i;

	g = (t_game *)malloc(sizeof(t_game));
	if (!g)
		return (game_error(NULL, "new_game malloc() of g"));
	g->boardsize = size;
	g->num_turns = ((size * size) * 1.5);
	g->turn_number = 0;
	if (make_players(g))
		return (game_error(g, "new_game make_players()"));
	g->turn = make_turns(g->num_turns);
	if (!g->turn)
		return (game_error(g, "new_game make_turns()"));

	i = 0;
	while (i < g->num_turns)
	{
		if (i % 2 == 0)
			g->turn[i] = new_turn(size, i, g->black);
		else
			g->turn[i] = new_turn(size, i, g->white);
		if (!g->turn[i])
		{
			del_game(g);
			return (game_error(NULL, "new_game malloc() of g->turn[i]"));
		}
		i++;
	}
	return (g);
}
