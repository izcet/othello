/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_move_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:48:44 by irhett            #+#    #+#             */
/*   Updated: 2018/01/31 18:58:28 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

#define GTURN g->turn[turn]

int			get_move_id(int move_number, int player_value, char *str)
{
	char	id[6] = {0, 0, 0, 0, 0, 0 };
	int		len;
	int		i;

	len = ft_numlen(move_number, 26);
	i = len - 1;
	while (i >= 0)
	{
		id[i] = 'a' + (move_number % 26);
		i--;
		move_number /= 26;
	}
	if (player_value == 2)
		ft_strtoupper(id);
	i = 0;
	while (id[i])
	{
		str[i] = id[i];
		i++;
	}
	return (i);
}

void		make_path(t_game *g)
{
	int				turn;
	int				p;
	char			path[g->turn_size * 4];
	struct stat		st = {};

	bzero(path, g->turn_size * 4);
	turn = 0;
	p = 0;
	while (turn < g->turn_last)
	{
		if (g->turn[turn]->move)
			p += get_move_id(GTURN->move->data->id, GTURN->active->value, &(path[p]));
		else
			path[p++] = (GTURN->active->value == 1 ? '0' : '1');
		if (stat(path, &st) == -1)
			mkdir(path, 0744);
		path[p++] = '/';
		turn++;
	}
	printf("path = \"%s\"\n", path);
}

void		save_file(t_game *g)
{
	(void)g;
}


