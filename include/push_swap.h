/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:55:04 by pcredibl          #+#    #+#             */
/*   Updated: 2019/11/01 14:13:58 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libftprintf.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
# define IMAX 2147483647

typedef struct		s_options
{
	int				fd;
	int				debug;
	int				clear;
	int				rec;
}					t_options;

typedef struct		s_lst
{
	int				num;
	struct s_lst	*next;
}					t_lst;

void				push(t_lst **lst_src, t_lst **lst_dst, int rec_mode,\
					int **com);

void				swap(t_lst *lst, int rec_mode, int **com);

int					rot(t_lst **lst, int rec_mode, int **com);

void				rev_rot(t_lst **lst, int rec_mode, int **com);

void				push_ch(t_lst **lst_src, t_lst **lst_dst);

void				swap_ch(t_lst *lst);

void				rot_ch(t_lst **lst);

void				rev_rot_ch(t_lst **lst);

void				print_lst(t_lst **lst_a, t_lst **lst_b);

t_lst				*lst_new(int num);

t_lst				*create_lst(char **argv);

void				ft_lstadd_ps(t_lst **alst, t_lst *new_lst);

char				**check_opt(char **argv, t_options *opt);

char				**checks(char **argv, t_options *opt);

int					find_size(t_lst *lst);

t_options			*new_opt(void);

void				check_fd(char *str, t_options *opt, char **line);

int					check_order(t_lst *lst_a, t_lst *lst_b);

void				operations(t_lst **stack_a, t_lst **stack_b,
					t_options *opt);

void				algo_a(t_lst **lst_a, t_lst **lst_b, int size, int *com);

void				algo_b(t_lst **lst_a, t_lst **lst_b, int size, int *com);

void				csort(t_lst **lst_a, t_lst **lst_b, int size, int *com);

int					is_operation(char *com);

void				algo3(t_lst **lst, int size, int*com);

void				algo3_dec(t_lst **lst, int size, int *com);

int					check_order3(t_lst *lst, int size);

int					check_order3_dec(t_lst *lst, int size);

void				algo_only3(t_lst **lst, int *com);

void				algo_only3_dec(t_lst **lst, int *com);

void				push_in_a(t_lst **lst_a, t_lst **lst_b, int *com);

void				set_debug(char *str, t_options *opt);

void				push_in_b(t_lst **lst_a, t_lst **lst_b, int size, int *com);

int					check_ord_1s(t_lst **lst, char ord);

int					check_ord_1s_ch(t_lst **lst, char ord);

void				optimization(int *com, t_options *opt);

void				print_com(int com, t_options *opt);

void				page_del_ps(t_lst **lst);

int					find_mediana(t_lst *lst, char stack, int size);

void				num_lst(t_lst *lst, int *num);

void				execute_com(t_lst **s_a, t_lst **s_b, char *com);
#endif
