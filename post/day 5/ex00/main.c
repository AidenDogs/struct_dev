/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:37:17 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 19:12:16 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "book.h"
#include "catalog.h"
#include "search.h"
#include "ui.h"
#include "getnextline/ft_printf.h"
#include <stdlib.h>

void display_error(const char *msg)
{
    ft_printf("Error: %s\n", msg);
}

int main(int argc, char **argv)
{
	t_book books[MAX_BOOKS];
	int count;
	int mode;
	char *query;

	if (argc != 2)
	{
		display_error("Usage: ./library <catalog_file>");
		return (1);
	}

	count = load_catalog(argv[1], books);
	if (count < 0)
	{
		display_error("Failed to open catalog file.");
		return (1);
	}

	mode = prompt_search_mode();
	query = prompt_query();

	if (mode == 1)
		search_by_title(books, count, query);
	else if (mode == 2)
		search_by_author(books, count, query);

	free(query);
	free_books(books, count);

	return (0);
}
