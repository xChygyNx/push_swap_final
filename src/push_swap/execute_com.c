/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_com.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:06:31 by pcredibl          #+#    #+#             */
/*   Updated: 2019/11/01 14:19:08 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		execute_com(t_lst **s_a, t_lst **s_b, char *com)
{
	!ft_strcmp(com, "sa") ? swap_ch(*s_a) : 0;
	!ft_strcmp(com, "sb") ? swap_ch(*s_b) : 0;
	!ft_strcmp(com, "ss") ? swap_ch(*s_a) : 0;
	!ft_strcmp(com, "ss") ? swap_ch(*s_b) : 0;
	!ft_strcmp(com, "pa") ? push_ch(s_b, s_a) : 0;
	!ft_strcmp(com, "pb") ? push_ch(s_a, s_b) : 0;
	!ft_strcmp(com, "ra") ? rot_ch(s_a) : 0;
	!ft_strcmp(com, "rb") ? rot_ch(s_b) : 0;
	!ft_strcmp(com, "rr") ? rot_ch(s_a) : 0;
	!ft_strcmp(com, "rr") ? rot_ch(s_b) : 0;
	!ft_strcmp(com, "rra") ? rev_rot_ch(s_a) : 0;
	!ft_strcmp(com, "rrb") ? rev_rot_ch(s_b) : 0;
	!ft_strcmp(com, "rrr") ? rev_rot_ch(s_a) : 0;
	!ft_strcmp(com, "rrr") ? rev_rot_ch(s_b) : 0;
	!is_operation(com) ? exit(ft_fprintf(2, "Error\n")) : 0;
}
