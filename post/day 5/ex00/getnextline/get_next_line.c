/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:24:36 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 19:03:57 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*saver(int i, char c, char *line, char **saves)
{
	char	*str;

	if (c == 'c')
	{
		line = strjo(line, *saves);
		free(*saves);
		*saves = NULL;
		return (line);
	}
	else
	{
		if (!line[i + 1])
			*saves = NULL;
		else
			*saves = ft_substr(line, i + 1, ft_strlen(line));
		str = ft_substr(line, 0, i + 1);
		return (free(line), str);
	}
}

t_helper	inithelper(void)
{
	t_helper	helper;

	*helper.buff = 0;
	helper.i = 0;
	helper.line = 0;
	helper.read_bytes = 0;
	return (helper);
}

char	*get_next_line(int fd)
{
	t_helper	helper;
	static char	*saves;

	helper = inithelper();
	if (ft_strlen(saves) > 0)
		helper.line = saver(0, 'c', helper.line, &saves);
	helper.read_bytes = BUFFER_SIZE;
	while (helper.read_bytes == BUFFER_SIZE && BUFFER_SIZE > 0)
	{
		helper.read_bytes = read(fd, helper.buff, BUFFER_SIZE);
		if (helper.read_bytes < 0)
			return (free(saves), saves = NULL, free(helper.line), NULL);
		helper.buff[helper.read_bytes] = '\0';
		if (ft_strlen(helper.buff) > 0)
			helper.line = strjo(helper.line, helper.buff);
		while (helper.line && helper.line[helper.i])
		{
			if (helper.line[helper.i] == '\n')
				return (saver(helper.i, ' ', helper.line, &saves));
			helper.i++;
		}
	}
	if (helper.line && helper.line[helper.i] == '\0')
		return (helper.line);
	return (NULL);
}

/* int	main()
{
	int fd = open("text.txt",O_RDONLY);
	int	u = 0;
	char *line;
	line = NULL;
	while(u < 30)
	{
		u++;
		line = get_next_line(fd);
		if(line == NULL)
		{
			printf("%s", line);
			break;
		}
		printf("%s", line);
		free(line);
	}
} */