/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:35:38 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 18:51:16 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
#define UI_H

int prompt_search_mode(void);
char *prompt_query(void);
void display_error(const char *msg);
void flush_stdin(void);

#endif
