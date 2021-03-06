/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 22:16:47 by pcredibl          #+#    #+#             */
/*   Updated: 2019/04/22 22:21:59 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	int		len;
	int		div;

	if (n == 0)
		return (1);
	div = 1000000000;
	len = 10;
	if (n < 0)
	{
		len++;
		div *= -1;
	}
	while (div != 0)
	{
		if (n / div != 0)
			break ;
		else
		{
			len--;
			div /= 10;
		}
	}
	return (len);
}
