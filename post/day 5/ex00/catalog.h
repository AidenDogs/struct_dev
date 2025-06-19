/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catalog.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:34:16 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 18:49:38 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATALOG_H
#define CATALOG_H

#include "book.h"

int load_catalog(const char *filename, t_book *books);
void free_books(t_book *books, int count);

#endif
