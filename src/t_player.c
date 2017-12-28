/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:38 by irhett            #+#    #+#             */
/*   Updated: 2017/12/28 00:20:03 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_player(t_player *p)
{
	if (p)
		free(p);
}

t_player	*new_player(char symbol, char value)
{
	t_player	*p;

	p = (t_player *)malloc(sizeof(t_player));
	if (!p)
		return (NULL);
	p->symbol = symbol;
	p->value = value;
	p->opponent = NULL;
	return (p);
}

t_player	*make_black_player(void)
{
	return (new_player('x', 1));
}

t_player	*make_white_player(void)
{
	return (new_player('o', 2));
}

int		make_players(t_game *g)
{
	g->black = make_black_player();
	g->white = make_white_player();
	if (g->black && g->white)
	{
		g->black->opponent = g->white;
		g->white->opponent = g->black;
		return (0);
	}
	return (1);
}
