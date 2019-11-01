/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:48:21 by pcredibl          #+#    #+#             */
/*   Updated: 2019/07/20 10:29:39 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_size(t_lst *lst)
{
	int		size;
	t_lst	*begin_lst;

	size = 1;
	begin_lst = lst;
	while (lst->next)
	{
		lst = lst->next;
		size++;
	}
	lst = begin_lst;
	return (size);
}

void	push_in_a(t_lst **lst_a, t_lst **lst_b, int *com)
{
	while (*lst_b)
		push(lst_b, lst_a, PA, &com);
}

void	push_in_b(t_lst **lst_a, t_lst **lst_b, int size, int *com)
{
	while (size--)
		push(lst_a, lst_b, PB, &com);
}

void	algo3(t_lst **lst, int size, int *com)
{
	int		was_ra;

	was_ra = 0;
	if (check_order3(*lst, size))
		return ;
	(*lst)->num < (*lst)->next->num ? was_ra++ : 0;
	(*lst)->num < (*lst)->next->num ? rot(lst, RA, &com) : 0;
	swap(*lst, SA, &com);
	if (check_order3(*lst, size) && !was_ra)
		return ;
	was_ra ? rev_rot(lst, RRA, &com) : rot(lst, RA, &com);
	was_ra = (was_ra + 1) % 2;
	if (check_order3(*lst, size) && !was_ra)
		return ;
	swap(*lst, SA, &com);
	if (check_order3(*lst, size) && !was_ra)
		return ;
	rev_rot(lst, RRA, &com);
	if (check_order3(*lst, size))
		return ;
	swap(*lst, SA, &com);
}

void	algo_only3(t_lst **lst, int *com)
{
	if (check_order3(*lst, 4) || find_size(*lst) == 1)
		return ;
	if (find_size(*lst) == 2)
	{
		(*lst)->num > (*lst)->next->num ? swap(*lst, SA, &com) : 0;
		return ;
	}
	(*lst)->num < (*lst)->next->num ? rev_rot(lst, RRA, &com) : 0;
	if (check_order3(*lst, 4))
		return ;
	(*lst)->num > (*lst)->next->num &&\
		(*lst)->num < (*lst)->next->next->num ? swap(*lst, SA, &com) : 0;
	if (check_order3(*lst, 4))
		return ;
	(*lst)->next->num < (*lst)->next->next->num ? rot(lst, RA, &com) :\
		swap(*lst, SA, &com);
	if (check_order3(*lst, 4))
		return ;
	rev_rot(lst, RRA, &com);
}
