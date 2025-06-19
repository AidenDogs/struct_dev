/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:45:52 by apeero            #+#    #+#             */
/*   Updated: 2025/06/12 15:41:17 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESYSTEM_H
# define FILESYSTEM_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>

typedef struct FSNode
{
	const char		*name;
	struct FSNode	*first_child;
	struct FSNode	*next_sibling;
	struct FSNode	*parent;
	int				size;
} FSNode;


FSNode *create_file(const char *name, int size);
FSNode *create_folder(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);

#endif