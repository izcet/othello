/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othello_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:52:12 by irhett            #+#    #+#             */
/*   Updated: 2017/12/17 18:22:58 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHELLO_STRUCTS_H
# define OTHELLO_STRUCTS_H

typedef struct		s_player
{
	char			symbol; // 'o' for black and 'x' for white
	char			value; // 1 or 2
//	unsigned int	color; // for graphical representations ?

}					t_player;

typedef struct		s_turn
{
	t_player		*active_player;
	t_board			*current_board;
	t_moves			*all_moves;
	t_moves			*unique_moves;

}					t_turn;

typedef struct		s_board
{


}					t_board;

typedef struct		s_game
{
	unsigned char	size; // default is 8x8
	unsigned long	estimated_games; // every fork
	unsigned long	current_game;
	t_board			*board; // array of N boards, where N == ( board_size^2 ) * 1.5
							// assumes each game runs 1 to 1, but with the potential of skipped turns
							// maybe


}					t_game;

typedef struct		s_world
{
	unsigned char	board_size;
	unsigned long	total_games;
	unsigned long	total_ties;
	unsigned long	total_wins_black;
	unsigned long	total_wins_white;
	unsigned long	total_board_win_black;
	unsigned long	total_board_win_white;
	unsigned long	total_board_incomplete;
	t_board			*smallest_end;


}					t_world;

#endif
