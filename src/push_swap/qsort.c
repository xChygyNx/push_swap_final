/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:35:58 by pcredibl          #+#    #+#             */
/*   Updated: 2019/07/22 16:36:00 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_mediana(t_lst *lst, char stack, int size)
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
		while (++i < size)
		{
			lst->num > cur->num ? mid-- : 0;
			lst->num < cur->num ? mid++ : 0;
			lst = lst->next;
		}
		if ((mid == 1 && stack == 'a') ||\
		(mid == -1 && stack == 'b') || !mid)
			return (cur->num);
		cur = cur->next;
	}
	return (cur->num);
}

static void	algo_a_logic(t_lst **lst_a, t_lst **lst_b, int size, int *com)
{
	int		mid;
	int		rev;
	int		side;

	mid = find_mediana(*lst_a, 'a', size);
	rev = 0;
	size /= 2;
	while (size)
	{
		(*lst_a)->num < mid ? size-- : rev++;
		(*lst_a)->num < mid ? push(lst_a, lst_b, PB, &com) :\
			rot(lst_a, RA, &com);
	}
	side = find_size(*lst_a) - rev > rev ? 1 : 0;
	rev = find_size(*lst_a) - rev < rev ? find_size(*lst_a) - rev : rev;
	while (rev--)
		side ? rev_rot(lst_a, RRA, &com) : rot(lst_a, RA, &com);
}

static void	algo_b_logic(t_lst **lst_a, t_lst **lst_b, int size, int *com)
{
	int		mid;
	int		rev;
	int		side;

	mid = find_mediana(*lst_b, 'b', size);
	size /= 2;
	rev = 0;
	while (size)
	{
		(*lst_b)->num > mid ? size-- : rev++;\
		(*lst_b)->num > mid ? push(lst_b, lst_a, PA, &com) :\
			rot(lst_b, RB, &com);
	}
	side = find_size(*lst_a) - rev > rev ? 1 : 0;
	rev = find_size(*lst_b) - rev < rev ? find_size(*lst_b) - rev : rev;
	while (rev--)
		side ? rev_rot(lst_b, RRB, &com) : rot(lst_b, RB, &com);
}

void		algo_a(t_lst **lst_a, t_lst **lst_b, int size, int *com)
{
	if (check_order(*lst_a, *lst_b))
		return ;
	if (size < 4)
	{
		find_size(*lst_a) < 4 ? algo_only3(lst_a, com) :\
			algo3(lst_a, size, com);
		return ;
	}
	algo_a_logic(lst_a, lst_b, size, com);
	algo_a(lst_a, lst_b, size / 2 + size % 2, com);
	algo_b(lst_a, lst_b, size / 2, com);
	size /= 2;
	while (size--)
		push(lst_b, lst_a, PA, &com);
}

void		algo_b(t_lst **lst_a, t_lst **lst_b, int size, int *com)
{
	if (lst_b && *lst_b && size < 4)
	{
		find_size(*lst_b) < 4 ? algo_only3_dec(lst_b, com) :\
			algo3_dec(lst_b, size, com);
		return ;
	}
	algo_b_logic(lst_a, lst_b, size, com);
	algo_b(lst_a, lst_b, size / 2 + size % 2, com);
	algo_a(lst_a, lst_b, size / 2, com);
	size /= 2;
	while (size--)
		push(lst_a, lst_b, PB, &com);
}
