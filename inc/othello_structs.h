/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othello_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:52:12 by irhett            #+#    #+#             */
/*   Updated: 2017/12/27 19:37:02 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHELLO_STRUCTS_H
# define OTHELLO_STRUCTS_H

/*
 * Key for Data Storage
 *
 * 	- In Memory (literal char values):
 * 		0 - Empty
 * 		1 - Black
 * 		2 - White
 * 		3+ Move IDs when checking availability
 *
 * 	- On Printout:
 * 		'-' - empty
 * 		'x' - black
 * 		'o' - white
 * 		'A-Z' (with padding) - Available Moves
 *
 * 	- File Naming:
 * 		'a-z' - black moves, in base 26 notation
 * 		'A-Z' - white moves, in base 26
 * 		'0' - black skipped turn
 * 		'1' - white skipped turn
 */

/*
 * A Player:
 * 	- Makes moves
 * 	- Takes turns with the opponent
 * 	- Has a number of tiles "owned" at the end of each turn
 */
typedef struct		s_player
{
	char			symbol; // 'o' for black and 'x' for white
	char			value; // 1 or 2 (black or white)
//	unsigned int	color; // for graphical representations ?
	struct s_player	*opponent;
	unsigned int	num_tiles;
}					t_player;

/*
 * A Board:
 * 	- Has a finite number of tiles
 * 	- Has some metadata about those tiles.
 * 	- Is always square
 * 	- Is used for one turn
 * 	- Has info about the active turn
 */
typedef struct		s_board
{
	char			**tiles;
	unsigned char	size;
	unsigned int	num_black;
	unsigned int	num_white;
	unsigned int	num_empty;
	t_turn			*turn;
}					t_board;

/*
 * A Move:
 * 	- Is made once.
 * 	- Has a location.
 * 	- Has a player making it
 * 	- Is specific to a specific board
 * 	- Is distinguishable from other moves
 * 	- Can be discarded if it is found to be duplicate to another move
 * 	- Stores some metadata about the move made
 */
typedef struct		s_move
{
	int				x;
	int				y;
	unsigned int	id; // which "move number" it is
	unsigned int	num_duplicates; // how many other moves collided with this one
	unsigned int	num_flipped; // how many tiles would be flipped by this move
	t_player		*player;
}					t_move;

/*
 * A Turn:
 * 	- Has an active player
 * 	- Has a single board
 * 	- Has multiple moves available
 * 	- Iterates through each possible move
 */
typedef struct		s_turn
{
	unsigned int	turn_id; // reference to the location in the game. //TODO not necesary?
	unsigned int	current_move; // iterate through unique moves
	t_player		*player;
	t_board			*board;
	t_move			*all_moves;
	t_move			*unique_moves;
}					t_turn;

/*
 * A Game:
 * 	- Has two players
 * 	- Has a finite number of turns (until end-of-game)
 * 	- Has one move per turn
 * 	- Has as many boards as there are moves made
 */
typedef struct		s_game
{
	unsigned char	board_size; // default is 8x8
	unsigned int	maximum; // (board_size * board_size) * 1.5
	unsigned int	turn_number; // starts at 0, the starting board with no moves made
	t_board			**board; // array of N boards, where N == maximum
							// assumes each game runs 1 to 1, but with the potential of skipped turns
							// maybe
	t_turn			**turn; // array of N turns, 

}					t_game;

/*
 * A World:
 * 	- Iterates through every single game
 * 	- Keeps track of the metadata accumulated
 * 	- Compares the current game data to previous games
 */
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
	t_game			*current; // game root
}					t_world;

#endif
