/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_turn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:42 by irhett            #+#    #+#             */
/*   Updated: 2018/02/02 15:57:31 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_turn(t_turn *t)
{
	unsigned char	i;
	t_movelist		*temp;

	if (t)
	{
		if (t->board)
		{
			i = 0;
			while (i < g_boardsize)
			{
				if (t->board[i])
					free(t->board[i]);
				i++;
			}
			free(t->board);
		}
		while (t->move)
		{
			temp = t->move->next;
			del_movelist(t->move);
			t->move = temp;
		}
		free(t);
	}
}

t_turn	*new_turn(t_player *active)
{
	t_turn			*t;
	unsigned int	i;

	t = (t_turn *)malloc(sizeof(t_turn));
	if (!t)
		return (NULL);
	ft_bzero(t, sizeof(t_turn));
	t->board = (unsigned char **)malloc(sizeof(unsigned char *) * g_boardsize);
	if (!t->board)
		return (game_error(t, "new_turn malloc() of t->board"));
	i = 0;
	while (i < g_boardsize)
	{
		t->board[i] = (unsigned char *)malloc(sizeof(unsigned char) * SIZE);
		if (!t->board[i])
		{
			del_turn(t);
			return (game_error(NULL, "new_turn malloc() of t->board[i]"));
		}
		ft_bzero(t->board[i++], g_boardsize);
	}
	t->num_empty = g_boardsize * g_boardsize;
	t->active = active;
	t->move = NULL;
	return (t);
}
