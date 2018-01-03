/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:52:13 by irhett            #+#    #+#             */
/*   Updated: 2018/01/03 12:20:46 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

int			game_usage(char	*exec)
{
	ft_usage(exec, "[-psv] [...]");
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
		if (ft_equals(argv[i], "-p") || ft_equals(argv[i], "-s"))
		{
			if (i + 1 >= argc)
				return (parse_error(argv[i], "flag requires argument"));
			i++;
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
	int		ret;
	char	*dir;

	dir = ft_strjoin(d->prefix, "/a");
	ret = mkdir(dir, DIRFLAGS);
	free(dir);
	if (ret)
		return (parse_error("Unable to create directory:", strerror(errno)));
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
	start_solve(data);
	print_stats(data);
	del_data(data);
	return (0);
}
