/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othello.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:52:12 by irhett            #+#    #+#             */
/*   Updated: 2017/12/23 13:54:33 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHELLO_H
# define OTHELLO_H

#include <sys/stat.h>
#include <sys/types.h>

#include "libft.h"
#include "othello_structs.h"

// man 2 stat
// man 2 mkdir

/*
 * struct stat st = {0};
 *
 * if (stat("/some/dir", &st) == -1) {
 * 	mkdir("/some/dir", 0700);
 * }
 */

char	*get_move_id(int move_num, int player_id);

#endif
