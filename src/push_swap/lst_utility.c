/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:58:28 by pcredibl          #+#    #+#             */
/*   Updated: 2019/11/01 13:58:30 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_lstadd_ps(t_lst **alst, t_lst *new)
{
	if (new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_options		*new_opt(void)
{
	t_options	*opt;

	opt = (t_options*)malloc(sizeof(t_options));
	opt->fd = 1;
	opt->rec = 0;
	opt->clear = 0;
	opt->debug = -1;
	return (opt);
}

t_lst			*lst_new(int num)
{
	t_lst		*lst_new;

	lst_new = (t_lst*)malloc(sizeof(t_lst));
	if (lst_new == NULL)
		return (NULL);
	lst_new->num = num;
	lst_new->next = NULL;
	return (lst_new);
}

void			print_lst(t_lst **lst_a, t_lst **lst_b)
{
	t_lst		*temp_a;
	t_lst		*temp_b;
	static int	i;

	temp_a = *lst_a;
	temp_b = *lst_b;
	ft_printf("--------------------------------\n");
	ft_printf("|%10s\t|%10s\t|\n", "Stack A", "Stack B");
	ft_printf("--------------------------------\n");
	while (temp_a || temp_b)
	{
		temp_a ? ft_printf("|%10d\t", temp_a->num) : ft_printf("|%10s\t", "");
		temp_a = temp_a != NULL ? temp_a->next : NULL;
		temp_b ? ft_printf("|%10d\t|\n", temp_b->num) :\
			ft_printf("|%10s\t|\n", "");
		temp_b = temp_b ? temp_b->next : NULL;
	}
	ft_printf("--------------------------------\n");
	ft_printf("%21s %d", "Actions:", i);
	ft_printf("\n\n");
	i++;
}

t_lst			*create_lst(char **argv)
{
	int			i;
	t_lst		*begin;
	t_lst		*temp;

	i = 0;
	begin = lst_new(ft_atoi_ps(argv[i]));
	temp = begin;
	while (argv[++i])
	{
		temp->next = lst_new(ft_atoi_ps(argv[i]));
		temp = temp->next;
	}
	return (begin);
}
