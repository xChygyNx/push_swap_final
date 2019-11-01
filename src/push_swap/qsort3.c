/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:44:32 by pcredibl          #+#    #+#             */
/*   Updated: 2019/07/20 10:27:02 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		algo3_dec(t_lst **lst, int size, int *com)
{
	int		was_ra;

	was_ra = 0;
	if (check_order3_dec(*lst, size))
		return ;
	size == 2 ? swap(*lst, SB, &com) : 0;
	if (size == 2)
		return ;
	(*lst)->num > (*lst)->next->num ? was_ra++ : 0;
	(*lst)->num > (*lst)->next->num ? rot(lst, RB, &com) : 0;
	swap(*lst, SB, &com);
	if (check_order3_dec(*lst, size) && !was_ra)
		return ;
	was_ra ? rev_rot(lst, RRB, &com) : rot(lst, RB, &com);
	was_ra = (was_ra + 1) % 2;
	if (check_order3_dec(*lst, size) && !was_ra)
		return ;
	swap(*lst, SB, &com);
	if (check_order3_dec(*lst, size) && !was_ra)
		return ;
	rev_rot(lst, RRB, &com);
	if (check_order3_dec(*lst, size))
		return ;
	swap(*lst, SB, &com);
}

void		algo_only3_dec(t_lst **lst, int *com)
{
	if (check_order3_dec(*lst, 4) || find_size(*lst) == 1)
		return ;
	if (find_size(*lst) == 2)
	{
		(*lst)->num < (*lst)->next->num ? rev_rot(lst, RRB, &com) : 0;
		return ;
	}
	(*lst)->num > (*lst)->next->num ? rev_rot(lst, RRB, &com) : 0;
	if (check_order3_dec(*lst, 4))
		return ;
	(*lst)->num > (*lst)->next->next->num ? swap(*lst, SB, &com) : 0;
	if (check_order3_dec(*lst, 4))
		return ;
	(*lst)->next->num > (*lst)->next->next->num ?\
	rot(lst, RB, &com) : swap(*lst, SB, &com);
	if (check_order3_dec(*lst, 4))
		return ;
	rev_rot(lst, RRB, &com);
}
