/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:35:15 by pcredibl          #+#    #+#             */
/*   Updated: 2019/07/22 16:35:18 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_operation(char *com)
{
	if (!ft_strcmp(com, "sa") || !ft_strcmp(com, "sb") || !ft_strcmp(com, "ss")\
		|| !ft_strcmp(com, "pa") || !ft_strcmp(com, "pb") || \
		!ft_strcmp(com, "ra") || !ft_strcmp(com, "rb") || \
		!ft_strcmp(com, "rr") || !ft_strcmp(com, "rra") || \
		!ft_strcmp(com, "rrb") || !ft_strcmp(com, "rrr"))
	{
		return (1);
	}
	return (0);
}

int			check_order3(t_lst *lst, int size)
{
	t_lst	*begin_lst;
	int		i;

	if (!lst->next)
		return (1);
	begin_lst = lst;
	i = 0;
	while (lst->next && ++i < size)
	{
		if (lst->num > lst->next->num)
		{
			lst = begin_lst;
			return (0);
		}
		lst = lst->next;
	}
	lst = begin_lst;
	return (1);
}

int			check_order3_dec(t_lst *lst, int size)
{
	t_lst	*begin_lst;
	int		i;

	if (!lst->next)
		return (1);
	begin_lst = lst;
	i = 0;
	while (lst->next && ++i < size)
	{
		if (lst->num < lst->next->num)
		{
			lst = begin_lst;
			return (0);
		}
		lst = lst->next;
	}
	lst = begin_lst;
	return (1);
}

int			check_ord_1s(t_lst **lst, char ord)
{
	t_lst *begin;

	begin = *lst;
	while (*lst && (*lst)->next)
	{
		if (((*lst)->num > (*lst)->next->num && ord == '+') ||\
				((*lst)->num < (*lst)->next->num && ord == '-'))
		{
			*lst = begin;
			return (0);
		}
		*lst = (*lst)->next;
	}
	*lst = begin;
	return (1);
}

int			check_ord_1s_ch(t_lst **lst, char ord)
{
	t_lst	*begin;

	begin = *lst;
	while (*lst && (*lst)->next)
	{
		if (((*lst)->num > (*lst)->next->num && ord == '+') ||\
				((*lst)->num < (*lst)->next->num && ord == '-'))
		{
			*lst = begin;
			return (0);
		}
		*lst = (*lst)->next;
	}
	*lst = begin;
	return (1);
}
