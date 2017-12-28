/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 19:22:13 by irhett            #+#    #+#             */
/*   Updated: 2017/12/27 19:24:04 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	*game_error(void *cleanup, char *message)
{
	if (cleanup)
		free(cleanup);
	ft_putstr_fd("Othello Error: ", 2);
	ft_putendl_fd(message, 2);
	return (NULL);
}
