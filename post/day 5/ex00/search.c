/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:41:38 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 18:59:42 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search.h"
#include "libft/libft.h"
#include <stdlib.h>

static int str_contains_case_insensitive(const char *haystack, const char *needle)
{
	int i, j;

	if (!needle || !haystack)
		return (0);

	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j])
		{
			if (ft_tolower(haystack[i + j]) != ft_tolower(needle[j]))
				break;
			j++;
		}
		if (needle[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static void print_book(t_book *book)
{
	ft_printf("ID: %d\nTitle: %s\nAuthor: %s\n\n", book->id, book->title, book->author);
}

void search_by_title(t_book *books, int count, const char *query)
{
	int found = 0;

	for (int i = 0; i < count; i++)
	{
		if (str_contains_case_insensitive(books[i].title, query))
		{
			print_book(&books[i]);
			found = 1;
		}
	}
	if (!found)
		ft_printf("No matching books found.\n");
}

void search_by_author(t_book *books, int count, const char *query)
{
	int found = 0;

	for (int i = 0; i < count; i++)
	{
		if (str_contains_case_insensitive(books[i].author, query))
		{
			print_book(&books[i]);
			found = 1;
		}
	}
	if (!found)
		ft_printf("No matching books found.\n");
}
