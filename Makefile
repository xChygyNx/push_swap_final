# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 16:20:36 by pcredibl          #+#    #+#              #
#    Updated: 2019/11/01 14:11:41 by pcredibl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftpushswap.a

CC = gcc
OBJ_PATH = ./
INC_PATH = ./include
LIBFT_PATH = ./src/libft
PRINTF_PATH = ./src/libft/ft_printf
PUSH_SWAP_PATH = ./src/push_swap
CFLAGS = -g -Wall -Wextra -Werror
LFLAGS = -I $(INC_PATH)
MAIN_PATH = ./main/

SOURCES_LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
		   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
		   ft_strncpy.c	ft_strcat.c	ft_strncat.c ft_strlcat.c ft_strchr.c\
		   ft_strrchr.c ft_strstr.c	ft_strnstr.c ft_strcmp.c ft_strncmp.c\
		   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
		   ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c	ft_memdel.c\
		   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
		   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
		   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
		   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
		   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
		   ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_del_mem.c\
		   ft_free_arr.c ft_isspace.c ft_strsplit_sp.c ft_int_len.c\
		   get_next_line.c ft_max.c ft_min.c ft_abs.c ft_putchar_utf8.c\
		   ft_putchar_utf8_fd.c ft_llitoa.c ft_strjoin_f.c ft_strjoin_s.c\
		   ft_putstr_utf8.c ft_putstr_utf8_fd.c ft_to_uppercase.c ft_lstrlen.c\
		   ft_putnstr_utf8_fd.c ft_lenwchar.c page_del.c free_tab.c word_len.c\
		   word_count.c

SOURCES_PRINTF = ft_putnbr_f.c print_str.c print_pointer.c utility_func.c\
			print_num.c print_char.c ft_printf.c parse_mod.c print_double.c\
			set_color.c long_arithmetic.c long_arithmetic_2.c count_print.c\
		   ft_dtoa.c ft_dtoa_2.c ft_dtoa_3.c ft_fprintf.c set_precision.c\
		   print_binary.c ft_dtoe.c print_scientific.c utility_func_2.c

PUSH_SWAP_SRC = lst_utility.c operations.c operations_ch.c check.c check2.c bonus.c\
				qsort.c qsort2.c qsort3.c csort.c optimization.c utility.c\
				execute_com.c

SRCS = $(addprefix $(LIBFT_PATH)/,$(SOURCES_LIBFT))
SRCS += $(addprefix $(PRINTF_PATH)/,$(SOURCES_PRINTF))
SRCS += $(addprefix $(PUSH_SWAP_PATH)/,$(PUSH_SWAP_SRC))

OBJ = $(addprefix $(OBJ_PATH)/,$(SOURCES_LIBFT:.c=.o))
OBJ += $(addprefix $(OBJ_PATH)/,$(SOURCES_PRINTF:.c=.o))
OBJ += $(addprefix $(OBJ_PATH)/,$(PUSH_SWAP_SRC:.c=.o))

all: re
	@$(CC) $(LFLAGS) $(CFLAGS) -g $(MAIN_PATH)main_checker.c $(NAME) -o checker
	@$(CC) $(LFLAGS) $(CFLAGS) -g $(MAIN_PATH)main_pusher.c $(NAME) -o push_swap
	@$(MAKE) clean


$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o:$(LIBFT_PATH)/%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o:$(PRINTF_PATH)/%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o:$(PUSH_SWAP_PATH)/%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

main: re
	@$(CC) $(LFLAGS) $(MAIN_PATH)main.c $(NAME) -o push_swap
	@$(MAKE) clean

checker: re
	@$(CC) $(LFLAGS) $(CFLAGS) -g $(MAIN_PATH)main_checker.c $(NAME) -o checker
	@$(MAKE) clean

pusher: re
	@$(CC) $(LFLAGS) $(CFLAGS) -g $(MAIN_PATH)main_pusher.c $(NAME) -o push_swap
	@$(MAKE) clean

norm:
	norminette $(LIBFT_PATH)
	norminette $(PRINTF_PATH)
	norminette $(PUSH_SWAP_PATH)
	norminette $(INC_PATH)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@rm -f push_swap
	@rm -f checker

re: fclean $(NAME)
