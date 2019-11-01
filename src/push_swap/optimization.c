/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:00:14 by pcredibl          #+#    #+#             */
/*   Updated: 2019/11/01 14:03:10 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	del_com_cond(int c1, int c2)
{
	if ((RA == c1 && RRA == c2) || (RRA == c1 && RA == c2) ||\
		(RB == c1 && RRB == c2) || (RRB == c1 && RB == c2) ||\
		(PA == c1 && PB == c2) || (PB == c1 && PA == c2))
		return (1);
	return (0);
}

static int	pair_com_cond(int c1, int c2)
{
	if ((SA == c1 && SB == c2) || (SB == c1 && SA == c2))
		return (3);
	if ((RA == c1 && RB == c2) || (RB == c1 && RA == c2))
		return (8);
	if ((RRA == c1 && RRB == c2) || (RRB == c1 && RRA == c2))
		return (11);
	return (c1);
}

static void	del_com(int *com)
{
	int		i;
	int		j;

	i = 0;
	while (com[i + 1])
	{
		j = 0;
		while (del_com_cond(com[i - j], com[i + j + 1]))
		{
			com[i - j] = 12;
			j++;
			com[i + j] = 12;
		}
		i += j + 1;
	}
}

static void	pair_com(int *com)
{
	int		i;
	int		j;

	i = 0;
	while (com[i + 1])
	{
		j = 0;
		while (pair_com_cond(com[i - j], com[i + j + 1]) != com[i - j])
		{
			com[i - j] = pair_com_cond(com[i - j], com[i + j + 1]);
			j++;
			com[i + j] = 12;
		}
		i += j + 1;
	}
}

void		optimization(int *com, t_options *opt)
{
	int		i;

	if (!com)
		return ;
	i = -1;
	del_com(com);
	pair_com(com);
	while (com[++i])
		print_com(com[i], opt);
	free(com);
}
