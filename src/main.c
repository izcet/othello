/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:52:13 by irhett            #+#    #+#             */
/*   Updated: 2017/12/30 17:52:09 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

int			game_usage(char	*exec)
{
	ft_usage(exec, "[-lpsv] [...]");
	ft_putendl("\t-l <file> | Logging (Default is STDOUT)");
	ft_putendl("\t-p <path> | Path of games data output (Default is here)");
	ft_putendl("\t-s <size> | Size (Default is 8)");
	ft_putendl("\t-v  [-v]  | Verbosity level (multiple flags stack)");
	return (0);
}

int			parse_error(char *first, char *second)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(first, 2);
	ft_putchar_fd(' ', 2);
	ft_putendl_fd(second, 2);
	return (1);
}

int			parse_args(t_data *d, int argc, char **argv)
{
	int				i;
	struct stat		st = {};

	i = 1;
	while (i < argc)
	{
		if (ft_equals(argv[i], "-l") || ft_equals(argv[i], "-p") || 
				ft_equals(argv[i], "-s"))
		{
			if (i + 1 >= argc)
				return (parse_error("-l", "flag must be used with argument"));
			i++;
			if (ft_equals(argv[i - 1], "-l"))
			{
			d->output_fd = open(argv[i], O_WRONLY | O_CREAT);
			if (d->output_fd < 0)
				return (parse_error("invalid file name:", argv[i]));
			}
			if (ft_equals(argv[i - 1], "-p"))
			{
				FREE_SET(d->prefix, ft_strdup(argv[i]));
				if (stat(d->prefix, &st) == -1)
					return (parse_error("invalid path:", argv[i]));
			}
			if (ft_equals(argv[i - 1], "-s"))
			{
				d->boardsize = ft_atoi(argv[i]);
				if (d->boardsize <= 0)
					return (parse_error("non-positive board size:", argv[i]));
				if (d->boardsize % 2)
					return (parse_error("board size must be even:", argv[i]));
			}
		}
		else if (ft_equals(argv[i], "-v"))
			d->verbosity++;
		else
			return (parse_error("unknown flag:", argv[i]));
		i++;
	}
	return (0);
}

int			validate_data(t_data *d)
{
	// check if I can write to that directory
	(void)d->prefix;
	return (0);
}

int			main(int argc, char **argv)
{
	t_data		*data;

	data = new_data();
	if (parse_args(data, argc, argv))
	{
		del_data(data);
		return (game_usage(argv[0]));
	}
	if (validate_data(data))
	{
		del_data(data);
		return (1);
	}

	if (data->verbosity >= 42) // because I don't think I'll do anything above 3
		ft_putendl_fd("This output is going to be hella verbose!", 
				data->output_fd);
	solve(data);
	del_data(data);
	return (0);
}
