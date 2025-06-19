/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:31:11 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 18:54:49 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <malloc.h>
# include <unistd.h>

typedef struct s_helper
{
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			read_bytes;
	int			i;

}	t_helper;

char	*get_next_line(int fd);
char	*strjo(char *s1, char *s2);
size_t	ft_strlen(char const *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif