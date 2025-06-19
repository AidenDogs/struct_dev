/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:18:38 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 19:12:34 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_conversions(char *str, va_list *arg);
int		ft_putnbr_unsigned_fd(unsigned int n, int fd);
int		ft_to_hex(unsigned int num, int fd, char c);
int		ft_print_memory_address(void *ptr, int fd);
#endif