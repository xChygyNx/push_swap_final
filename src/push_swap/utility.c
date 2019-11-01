/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:58:06 by pcredibl          #+#    #+#             */
/*   Updated: 2019/11/01 14:02:58 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_com(int com, t_options *opt)
{
	int		fd;

	fd = opt->rec ? open("test_empty.c", O_WRONLY | O_APPEND) : 1;
	com == SA ? ft_fprintf(fd, "sa\n") : 0;
	com == SB ? ft_fprintf(fd, "sb\n") : 0;
	com == SS ? ft_fprintf(fd, "ss\n") : 0;
	com == PA ? ft_fprintf(fd, "pa\n") : 0;
	com == PB ? ft_fprintf(fd, "pb\n") : 0;
	com == RA ? ft_fprintf(fd, "ra\n") : 0;
	com == RB ? ft_fprintf(fd, "rb\n") : 0;
	com == RR ? ft_fprintf(fd, "rr\n") : 0;
	com == RRA ? ft_fprintf(fd, "rra\n") : 0;
	com == RRB ? ft_fprintf(fd, "rrb\n") : 0;
	com == RRR ? ft_fprintf(fd, "rrr\n") : 0;
}

void	page_del_ps(t_lst **lst)
{
	t_lst	*temp;

	if (lst != NULL && *lst != NULL)
	{
		temp = *lst;
		while (temp != NULL)
		{
			temp = (*lst)->next;
			(*lst)->next = NULL;
			free(*lst);
			*lst = temp;
		}
	}
}

void	num_lst(t_lst *lst, int *num)
{
	t_lst	*begin;

	begin = lst;
	num[0] = lst->num;
	num[1] = -2147483648;
	num[2] = 2147483647;
	while (lst)
	{
		num[2] = lst->num < num[2] ? lst->num : num[2];
		num[1] = lst->num < num[0] && lst->num > num[1] ? lst->num : num[1];
		if (lst->num > num[0])
		{
			num[1] = num[0];
			num[0] = lst->num;
		}
		lst = lst->next;
	}
	lst = begin;
}
