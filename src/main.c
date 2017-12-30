/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:52:13 by irhett            #+#    #+#             */
/*   Updated: 2017/12/29 20:34:57 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"


int			game_usage(char	*exec)
{
	ft_usage(exec, "[-lpsv] [...]");
	ft_putendl("\t-l <file> | Logging (Default is STDOUT)");
	ft_putendl("\t-p <path> | Path of games data output (Default is CWD)");
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

int			parse_args(t_data *data, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (equals(argv[i], "-l") || equals(argv[i], "-p") || equals(argv[i], "-s"))
		{
			if (i + 1 >= argc)
				return (parse_error("-l", "flag must be used with argument"));
			i++;
			if (equals(argv[i - 1], "-l"))
			{
			d->output_fd = open(argv[i], O_WRONLY | O_CREAT);
			if (d->output_fd < 0)
				return (parse_error("invalid file name:", argv[i]));
			}
			if (equals(argv[i - 1], "-p"))
			{


			}
			if (equals(argv[i - 1], "-s"))
			{

			}
		}
		else if (equals(argv[i], "-v"))
			d->verbosity++;
		else
			return (parse_error("Unknown flag:", argv[i]));
		i++;
	}
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
	solve(data);
	del_data(data);
	return (0);
}
