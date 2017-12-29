/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_turn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:42 by irhett            #+#    #+#             */
/*   Updated: 2017/12/28 20:15:14 by irhett           ###   ########.fr       */
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
			while (i < size)
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

t_turn	*new_turn(unsigned char size, unsigned int id, t_player *active)
{
	t_turn	*t;

	t = (t_turn *)malloc(sizeof(t_turn));
	if (!t)
		return (NULL);
	t->size = size;
	t->board = (char **)malloc(sizeof(char *) * size);
	if (!t->board)
		return (game_error(t, "new_turn malloc() of t->board"));
	i = 0;
	while (i < size)
	{
		t->board[i] = (char *)malloc(sizeof(char) * size);
		if (!t->board[i])
		{
			del_turn(t);
			return (game_error(NULL, "new_turn malloc() of t->board[i]"));
		}
		ft_bzero(t->board[i++], size);
	}
	t->num_black = 0;
	t->num_white = 0;
	t->num_empty = size * size;
	t->turn_id = id;
	t->active_player = active;
	t->move = NULL;
	return (t);
}
