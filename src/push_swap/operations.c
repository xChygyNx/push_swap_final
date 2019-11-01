/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:34:26 by pcredibl          #+#    #+#             */
/*   Updated: 2019/07/22 16:34:29 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_lst **lst_src, t_lst **lst_dst, int rec_mode, int **com)
{
	t_lst	*temp;

	if (lst_src && *lst_src)
	{
		temp = *lst_src;
		*lst_src = temp->next;
		ft_lstadd_ps(lst_dst, temp);
		while (**com)
			(*com)++;
		**com = rec_mode;
		(*com)++;
		**com = 0;
	}
}

void	swap(t_lst *lst, int rec_mode, int **com)
{
	int		temp;

	if (lst && lst->next)
	{
		temp = lst->next->num;
		lst->next->num = lst->num;
		lst->num = temp;
		while (**com)
			(*com)++;
		**com = rec_mode;
		(*com)++;
		**com = 0;
	}
}

int		rot(t_lst **lst, int rec_mode, int **com)
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
		while (**com)
			(*com)++;
		**com = rec_mode;
		(*com)++;
		**com = 0;
		return (1);
	}
	return (0);
}

void	rev_rot(t_lst **lst, int rec_mode, int **com)
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
		while (**com)
			(*com)++;
		**com = rec_mode;
		(*com)++;
		**com = 0;
	}
}
