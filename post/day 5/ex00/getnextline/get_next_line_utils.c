/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:30:55 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 19:07:28 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*strjo(char *s1, char *s2)
{
	int		i;
	char	*joinstr;

	i = 0;
	joinstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (joinstr == NULL)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		joinstr[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		joinstr[i] = *s2;
		s2++;
		i++;
	}
	joinstr[i] = '\0';
	return (free(s1), joinstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	substr = (char *)malloc((len + 1));
	while (len > 0 && s[start] != '\0')
	{
		substr[i] = s[start];
		i++;
		start++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
