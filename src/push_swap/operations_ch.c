/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:01:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/11/01 14:14:31 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_ch(t_lst **lst_src, t_lst **lst_dst)
{
	t_lst	*temp;

	if (lst_src && *lst_src)
	{
		temp = *lst_src;
		*lst_src = temp->next;
		ft_lstadd_ps(lst_dst, temp);
	}
}

void	swap_ch(t_lst *lst)
{
	int		temp;

	if (lst && lst->next)
	{
		temp = lst->next->num;
		lst->next->num = lst->num;
		lst->num = temp;
	}
}

void	rot_ch(t_lst **lst)
{
	t_lst	*temp;
	t_lst	*begin;

	if (*lst && (*lst)->next)
	{
		temp = (*lst);
		begin = (*lst)->next;
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = temp;
		(*lst)->next->next = NULL;
		*lst = begin;
	}
}

void	rev_rot_ch(t_lst **lst)
{
	t_lst	*temp;
	t_lst	*begin;

	if (*lst && (*lst)->next)
	{
		begin = *lst;
		while ((*lst)->next->next)
			(*lst) = (*lst)->next;
		temp = (*lst)->next;
		(*lst)->next = NULL;
		temp->next = begin;
		*lst = temp;
	}
}

void	operations(t_lst **s_a, t_lst **s_b, t_options *opt)
{
	char	*com;

	com = (char*)malloc(sizeof(char));
	opt->fd != 1 ? get_next_line(0, &com) : 0;
	while (get_next_line(0, &com))
	{
		execute_com(s_a, s_b, com);
		free(com);
		opt->clear ? system("clear") : 0;
		opt->debug >= 0 ? (print_lst(s_a, s_b)) : 0;
		opt->debug >= 0 ? usleep(opt->debug * 15000) : 0;
	}
}
