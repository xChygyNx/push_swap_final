/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:57:28 by pcredibl          #+#    #+#             */
/*   Updated: 2019/11/01 13:57:51 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_fd(char *str, t_options *opt, char **line)
{
	int			fd;
	char		*file;
	size_t		len;

	len = ft_strlen(str) == 0 ? 0 : ft_strlen(str) - 1;
	str[len] != '}' ? exit(ft_fprintf(2, "Usage: {file_name}\n")) : 0;
	file = (char*)malloc(sizeof(char) * len);
	file = ft_strncpy(file, str, len);
	opt->fd != 1 ? exit(ft_fprintf(2, "Error (must be one file in work!)")) : 0;
	fd = open(file, O_RDONLY);
	get_next_line(fd, line);
	fd < 1 ? exit(ft_fprintf(2, "Error (failure by open file)\n")) : 0;
	close(fd);
	opt->fd = fd;
	free(file);
}

void	set_debug(char *str, t_options *opt)
{
	int		num;

	if (!*str)
	{
		opt->debug = 0;
		return ;
	}
	if (*str == 'a')
	{
		str++;
		opt->clear = 1;
	}
	num = ft_atoi(str);
	ft_printf("str = %s\n", str);
	!ft_isdigit(*str) || *++str ?\
		exit(ft_fprintf(2, "Usage: for set delay, input d[0-9] or da[0-9]\n"))\
		: 0;
	opt->debug = num;
}
