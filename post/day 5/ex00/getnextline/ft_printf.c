/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:16:26 by apeero            #+#    #+#             */
/*   Updated: 2024/12/04 18:16:27 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		value;

	value = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i] != '\0')
		{
			value += ft_conversions((char *)&str[i], &arg);
			i++;
		}
		else
			value += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(arg);
	return (value);
}
