/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:58:48 by pcredibl          #+#    #+#             */
/*   Updated: 2019/11/01 13:59:30 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		**check_opt(char **argv, t_options *opt)
{
	while (*argv)
	{
		if (**argv != '-' && !ft_isdigit(**argv))
			exit(ft_fprintf(2, "Error\n"));
		if (**argv == '-')
		{
			if (*(*argv + 1) != 'd' && *(*argv + 1) != 'r' &&\
				!ft_isdigit(*(*argv + 1)))
				exit(ft_fprintf(2, "Error\n"));
			if (*(*argv + 1) == 'd')
				set_debug((*argv) + 2, opt);
			if (*(*argv + 1) == 'r')
				opt->rec = 1;
		}
		if (**argv == '-' ? ft_isdigit(*(*argv + 1)) : ft_isdigit(**argv))
			break ;
		argv++;
	}
	return (argv);
}

static void	check_dub(char **c_tab)
{
	int		i;
	int		j;

	i = -1;
	while (c_tab[++i])
	{
		j = i;
		while (c_tab[++j])
			ft_atoi(c_tab[i]) == ft_atoi(c_tab[j]) ?\
			exit(ft_fprintf(2, "Error\n")) : 0;
	}
}

static void	check_num(char **c_tab)
{
	int		i;
	int		j;

	i = -1;
	while (c_tab[++i])
	{
		j = 0;
		while (c_tab[i][j])
		{
			ft_isdigit(c_tab[i][j]) || ((c_tab[i][j] == '-' ||\
			c_tab[i][j] == '+') && j == 0) ? 0 :\
			exit(ft_fprintf(2, "Error\n"));
			j++;
		}
	}
}

int			check_order(t_lst *lst_a, t_lst *lst_b)
{
	if (lst_b)
		return (0);
	if (check_ord_1s(&lst_a, '+') && check_ord_1s(&lst_b, '-'))
		return (1);
	return (0);
}

char		**checks(char **argv, t_options *opt)
{
	char	*line;

	line = NULL;
	!argv || !(*argv) ? exit(0) : 0;
	if (!ft_strcmp(*argv, "-r"))
	{
		argv++;
		opt->rec = 1;
	}
	**argv == '{' ? check_fd(*argv + 1, opt, &line) : 0;
	*(argv + 1) && opt->fd > 1 ?\
		exit(ft_printf("Usage: program {file} <no flags & arguments>\n")) : 0;
	opt->fd != 1 && !line ? exit(ft_fprintf(2, "Error (empty file)\n")) : 0;
	opt->fd != 1 ? ft_printf("%s\n", line) : 0;
	argv = opt->fd != 1 ? ft_strsplit((char const*)line, ' ') : argv;
	argv = check_opt(argv, opt);
	check_dub(argv);
	check_num(argv);
	opt->fd == 1 || !opt->rec ? 0 : close(opt->fd);
	return (argv);
}
