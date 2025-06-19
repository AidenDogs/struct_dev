/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:43:40 by apeero            #+#    #+#             */
/*   Updated: 2024/12/05 19:43:42 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(unsigned int n)
{
	int		number;

	number = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		number++;
	}
	return (number);
}

static void	ft_to_hex_uppercase(unsigned int num, int fd)
{
	int		bf;
	char	*bff;

	bff = "0123456789ABCDEF";
	if (num == 0)
		return ;
	bf = (((unsigned char) num) % 16);
	num /= 16;
	ft_to_hex_uppercase(num, 1);
	write(fd, &bff[bf], 1);
}

static void	ft_to_hex_lowercase(unsigned int num, int fd)
{
	int		bf;
	char	*bff;

	bff = "0123456789abcdef";
	if (num == 0)
		return ;
	bf = (((unsigned char) num) % 16);
	num /= 16;
	ft_to_hex_lowercase(num, 1);
	write(fd, &bff[bf], 1);
}

int	ft_to_hex(unsigned int num, int fd, char c)
{
	if (num == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (c == 'x')
		ft_to_hex_lowercase(num, fd);
	else
		ft_to_hex_uppercase(num, fd);
	return (count_digit(num));
}
