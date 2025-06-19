/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:42:58 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 19:15:17 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "getnextline/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int prompt_search_mode(void)
{
    char *line;
    int choice;

    while (1)
    {
        ft_printf("Search by:\n1. Title\n2. Author\nEnter 1 or 2: ");
        line = get_next_line(STDIN_FILENO);
        if (!line)
            continue;
        // Trim newline and spaces
        char *trimmed = ft_strtrim(line, " \t\n\v\f\r");
        free(line);
        if (!trimmed)
            continue;
        if (ft_strlen(trimmed) == 1 && (trimmed[0] == '1' || trimmed[0] == '2'))
        {
            choice = trimmed[0] - '0';
            free(trimmed);
            return choice;
        }
        free(trimmed);
        ft_printf("Invalid input. Please enter 1 or 2.\n");
    }
}

char *prompt_query(void)
{
	char *line;
	char *trimmed;

	while (1)
	{
		ft_printf("Enter search substring: ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
			continue;
		trimmed = ft_strtrim(line, " \t\n\v\f\r");
		free(line);
		if (trimmed && *trimmed)
			return trimmed;
		free(trimmed);
	}
}
