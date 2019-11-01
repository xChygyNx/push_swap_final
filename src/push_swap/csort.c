/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:59:28 by pcredibl          #+#    #+#             */
/*   Updated: 2019/11/01 13:59:42 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	def_side(t_lst *lst, int *num)
{
	t_lst	*begin;
	int		size;
	int		i;

	begin = lst;
	size = find_size(lst);
	i = 0;
	while (lst->num != num[0])
	{
		i++;
		lst = lst->next;
	}
	lst = begin;
	return (size - i > i ? 1 : 0);
}

static int	mid_less(t_lst *lst, int size, int up)
{
	int		mid;
	t_lst	*cur;
	t_lst	*begin;
	int		i;

	begin = lst;
	cur = lst;
	while (1)
	{
		lst = begin;
		mid = 0;
		i = -1;
		while (++i < size && cur->num < up)
		{
			if (lst->num < up)
				lst->num > cur->num ? mid-- : mid++;
			lst = lst->next;
		}
		if (cur->num < up && (mid == 1 || !mid))
			return (cur->num);
		cur = cur->next;
	}
	return (cur->num);
}

static int	get_back(t_lst **lst_a, t_lst **lst_b, int *com)
{
	int		num[3];
	int		side;
	int		rev;

	rev = 0;
	while (*lst_b)
	{
		num_lst(*lst_b, num);
		side = def_side(*lst_b, num);
		while ((*lst_b)->num != num[0])
		{
			if ((*lst_b)->num != num[1] && (*lst_b)->num != num[2])
				side ? rot(lst_b, RB, &com) : rev_rot(lst_b, RRB, &com);
			else
			{
				push(lst_b, lst_a, PA, &com);
				rev += (*lst_a)->num == num[2] ? rot(lst_a, RA, &com) : 0;
			}
		}
		push(lst_b, lst_a, PA, &com);
		(*lst_a)->num > (*lst_a)->next->num ? swap(*lst_a, SA, &com) : 0;
	}
	return (rev);
}

static void	csort_logic(t_lst **lst_a, t_lst **lst_b, int size, int *com)
{
	int		mid;
	int		midless;

	com += 0;
	mid = find_mediana(*lst_a, 'a', find_size(*lst_a));
	midless = mid_less(*lst_a, find_size(*lst_a) / 2, mid);
	size /= 2;
	while (size)
	{
		(*lst_a)->num < mid ? size-- : 0;
		(*lst_a)->num < mid ? push(lst_a, lst_b, PB, &com) :\
			rot(lst_a, RA, &com);
		*lst_b && (*lst_b)->num < midless ? rot(lst_b, RB, &com) : 0;
	}
}

void		csort(t_lst **lst_a, t_lst **lst_b, int size, int *com)
{
	int		rev;

	if (check_order(*lst_a, *lst_b))
		return ;
	if (size < 4)
	{
		find_size(*lst_a) < 4 ? algo_only3(lst_a, com) :\
			algo3(lst_a, size, com);
		return ;
	}
	csort_logic(lst_a, lst_b, size, com);
	csort(lst_a, lst_b, size / 2 + size % 2, com);
	rev = get_back(lst_a, lst_b, com);
	while (rev--)
		rev_rot(lst_a, RRA, &com);
}
