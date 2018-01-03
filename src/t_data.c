/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 19:42:49 by irhett            #+#    #+#             */
/*   Updated: 2018/01/03 12:23:56 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_data(t_data *d)
{
	if (d)
	{
		if (d->prefix)
			free(d->prefix);
		del_game(d->game);
		free(d);
	}
}

t_data	*new_data(void)
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
		return (NULL);
	ft_bzero(d, sizeof(t_data));
	d->boardsize = 8;
	d->prefix = ft_strdup(".");
	d->game = NULL;
	return (d);
}
