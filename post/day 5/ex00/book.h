/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:33:57 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 18:49:31 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOK_H
#define BOOK_H

#define MAX_BOOKS 1000

typedef struct s_book {
    int id;
    char *title;
    char *author;
} t_book;

#endif
