/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 19:42:49 by irhett            #+#    #+#             */
/*   Updated: 2017/12/29 19:45:36 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_data(t_data *d)
{
	if (d)
	{
		if (d->prefix)
			free(d->prefix);
		del_world(d->world);
		free(d);
	}
}

t_data	*new_data(void)
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
		return (NULL);
	d->boardsize = 8;
	d->verbosity = 0;
	d->output_fd = 1;
	d->prefix = NULL;
	d->world = NULL;
	return (d);
}
