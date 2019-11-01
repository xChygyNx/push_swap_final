/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:55:53 by pcredibl          #+#    #+#             */
/*   Updated: 2019/11/01 13:55:54 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_options	*opt;
	t_lst		*stack_a;
	t_lst		*stack_b;
	int			k;

	argc < 2 ? exit(ft_fprintf(2, "Error\n")) : 0;
	k = argc == 2 ? 0 : 1;
	argv = argc == 2 ? ft_strsplit(argv[1], ' ') : argv;
	opt = NULL;
	opt = new_opt();
	argv = checks(argv + k, opt);
	stack_a = create_lst(argv);
	operations(&stack_a, &stack_b, opt);
	free(opt);
	ft_printf(check_ord_1s_ch(&stack_a, '+') && !stack_b ? "OK\n" : "KO\n");
	page_del_ps(&stack_a);
	stack_b ? page_del_ps(&stack_b) : 0;
	return (1);
}
