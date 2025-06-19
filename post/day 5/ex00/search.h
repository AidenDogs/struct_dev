/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:36:47 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 18:50:41 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH_H
#define SEARCH_H

#include "book.h"

void search_by_title(t_book *books, int count, const char *query);
void search_by_author(t_book *books, int count, const char *query);

#endif
