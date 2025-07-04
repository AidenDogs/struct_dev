/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:14:06 by giomastr          #+#    #+#             */
/*   Updated: 2025/06/08 19:03:30 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format(char c, va_list args)
{
	int	print_len;

	print_len = 0;
	if (c == '%')
		print_len += ft_putchar_fd(c, 1);
	else if (c == 'c')
		print_len += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		print_len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		print_len += ft_put_ptr(va_arg(args, uintptr_t));
	else if (c == 'd' || c == 'i')
		print_len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		print_len += ft_putnbr_base_fd(va_arg(args, unsigned int), BASE10, 1);
	else if (c == 'x')
		print_len += ft_putnbr_base_fd(va_arg(args, unsigned int), BASE16, 1);
	else if (c == 'X')
		print_len += ft_putnbr_base_fd(va_arg(args, unsigned int), BASE16UP, 1);
	return (print_len);
}

int	ft_printf(const char *form, ...)
{
	int			i;
	int			count;
	va_list		args;

	va_start (args, form);
	i = 0;
	count = 0;
	if (!form)
		return (-1);
	while (form[i] != '\0')
	{
		if (form[i] == '%' && form[i + 1])
			count += format(form[++i], args);
		else
			count += ft_putchar_fd(form[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
