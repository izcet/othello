/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othello_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:52:12 by irhett            #+#    #+#             */
/*   Updated: 2018/01/03 12:18:50 by irhett           ###   ########.fr       */
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
}					t_player;

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
	unsigned char	x;
	unsigned char	y;
	unsigned char	multiplier; // how many other moves collided with this one
								// starts at 1
								// increments per collision
	unsigned int	id; // which "move number" it is
	unsigned int	flipped; // how many tiles would be flipped by this move
	t_player		*player;
}					t_move;

/*
 * A Move List:
 * 	- Is a linked list of moves
 * 	- First a list of All Moves is compiled from the board state
 * 	- Then the duplicates are removed from the list
 * 	- The remaining moves are incremented for each corresponding duplicate
 */
typedef struct		s_mlist
{
	t_move			*data;
	struct s_mlist	*next;
}					t_movelist;

/*
 * A Turn:
 * 	- Has an active player
 * 	- Has a single board
 * 	- Has information about the state of the board at this turn (tiles)
 * 	- Has multiple moves available
 * 	- Iterates through each possible move
 */
typedef struct		s_turn
{
	unsigned char	size;
	unsigned char	**board;
	unsigned int	num_black;
	unsigned int	num_white;
	unsigned int	num_empty;
	unsigned int	turn_id; // location in the game. //TODO not necesary?
	unsigned int	current_move; // TODO not necessary?
	t_player		*active;
	t_movelist		*move; // iteration is done by popping the head
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
	unsigned char	boardsize; // default is 8x8
	unsigned int	num_turns; // for the array bounds
	unsigned int	turn_number; // starts at 0, 
								//the starting board with no moves made
	unsigned int	last_turn; // for the game
	t_turn			**turn; // array of N turns, where N == maximum
							// assumes each game runs 1 to 1, 
							// but with the potential of skipped turns
	t_player		*black;
	t_player		*white;
}					t_game;

/*
 * Data:
 * 	- Contains data about the application
 * 	- Verbosity level, etc
 * 	- Ouptut to stdout or to file for log information
 * 	- Location of game data output (for results)
 * 	- Iterates through every single game
 * 	- Keeps track of the metadata accumulated
 * 	- Compares the current game data to previous games
 */
typedef struct		s_data
{
	unsigned char	boardsize;
	unsigned char	verbosity; // for logging
	char			*prefix; // for output path
	
	// wins/loss/draw stats
	unsigned long	total_games;
	unsigned long	total_ties;
	unsigned long	total_wins_black;
	unsigned long	total_wins_white;
	unsigned long	total_board_win_black;
	unsigned long	total_board_win_white;
	unsigned long	total_board_incomplete;

	// individual turn stats
	unsigned long	most_tiles_flipped_black;
	unsigned long	most_tiles_flipped_white;

	// esoteric stats
	unsigned long	most_skipped_black_turns;
	unsigned long	most_skipped_white_turns;
	unsigned long	most_skipped_turns;
	unsigned long	most_consecutive_black_skips;
	unsigned long	most_consecutive_white_skips;

	t_game			*game; // game root
}					t_data;

#endif
