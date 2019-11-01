/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pusher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:55:43 by pcredibl          #+#    #+#             */
/*   Updated: 2019/11/01 13:56:14 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_options	*opt;
	t_lst		*stack_a;
	t_lst		*stack_b;
	int			*com;

	argc < 2 ? exit(ft_fprintf(2, "Error\n")) : 0;
	argv = argc == 2 ? ft_strsplit(argv[1], ' ') : argv;
	opt = new_opt();
	argv = argc == 2 ? checks(argv + 0, opt) : checks(argv + 1, opt);
	stack_a = create_lst(argv);
	com = (int*)malloc(sizeof(int) * find_size(stack_a) * find_size(stack_a));
	!com ? exit(ft_fprintf(2, "Error (can't allocate memoty)\n")) : 0;
	*com = 0;
	find_size(stack_a) < 4 ? algo_only3(&stack_a, com) : 0;
	find_size(stack_a) > 3 && find_size(stack_a) < 101 ?\
		csort(&stack_a, &stack_b, find_size(stack_a), com) : 0;
	find_size(stack_a) > 100 ?\
		algo_a(&stack_a, &stack_b, find_size(stack_a), com) : 0;
	optimization(com, opt);
	page_del_ps(&stack_a);
	stack_b ? page_del_ps(&stack_b) : 0;
	free(opt);
	return (1);
}
