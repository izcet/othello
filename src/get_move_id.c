/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_move_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:48:44 by irhett            #+#    #+#             */
/*   Updated: 2017/12/23 13:54:13 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

char	*get_move_id(int move_number, int player_id)
{
	char	*id;
	int		len;
	int		i;

	len = ft_numlen(move_number, 26);
	id = ft_strnew(len);
	if (!id)
		return (NULL);
	i = len;
	while (i >= 0)
	{
		id[i] = 'a' + move_number % 26;
		i--;
		move_number /= 26;
	}
	if (player_id)
		ft_strtoupper(id);
	return (id);
}
