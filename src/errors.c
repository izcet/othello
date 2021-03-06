/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 19:22:13 by irhett            #+#    #+#             */
/*   Updated: 2018/01/13 14:36:02 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

int			parse_error(char *first, char *second)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(first, 2);
	ft_putchar_fd(' ', 2);
	ft_putendl_fd(second, 2);
	return (1);
}

void	*game_error(void *cleanup, char *message)
{
	if (cleanup)
		free(cleanup);
	ft_putstr_fd("Othello Error: ", 2);
	ft_putendl_fd(message, 2);
	return (NULL);
}
