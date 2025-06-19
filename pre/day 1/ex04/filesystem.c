/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:43:06 by apeero            #+#    #+#             */
/*   Updated: 2025/06/12 15:44:20 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

FSNode	*create_file(const char *name, int size)
{
	FSNode *new_file;

	new_file = malloc(sizeof(FSNode));
	if (!new_file)
		return (NULL);
	new_file->name = strdup(name);
	new_file->size = size;
	new_file->parent = NULL;
	new_file->first_child = NULL;
	new_file->next_sibling = NULL;
	return (new_file);
}

FSNode *create_folder(const char *name)
{
	FSNode *new_folder;

	new_folder = malloc(sizeof(FSNode));
	if (!new_folder)
		return (NULL);
	new_folder->name = strdup(name);
	new_folder->size = 0;
	new_folder->parent = NULL;
	new_folder->first_child = NULL;
	new_folder->next_sibling = NULL;
	return (new_folder);
}

void add_child(FSNode *parent, FSNode *child)
{
	FSNode *curr;
	if (!parent || !child)
		return;
	if (parent->size > 0)
		return;
	if (parent->first_child == NULL)
		parent->first_child = child;
	else
	{
		curr = parent->first_child;
		while (curr->next_sibling != NULL)
			curr = curr->next_sibling;
		curr->next_sibling = child;
	}

	child->parent = parent;
	child->next_sibling = NULL;
}

FSNode *get_first_child(const FSNode *parent)
{
	if (!parent) 
		return (NULL);
	return (parent->first_child);
}

FSNode *get_next_sibling(const FSNode *node)
{
	if (!node)
		return (NULL);
	return (node->next_sibling);
}

/* void print_tree(const FSNode *node, int level)
{
	for (int i = 0; i < level; i++)
		printf("   ");

	printf("|- %s", node->name);
	if (node->size > 0)
		printf(" (file, size=%d)", node->size);
	else
		printf(" (folder)");

	printf("\n");

	for (FSNode *child = node->first_child; child != NULL; child = child->next_sibling)
		print_tree(child, level + 1);
}

void free_tree(FSNode *node)
{
	if (!node) return;

	FSNode *child = node->first_child;
	while (child != NULL)
	{
		FSNode *next = child->next_sibling;
		free_tree(child);
		child = next;
	}

	free((void*)node->name);
	free(node);
}

int main(void)
{
	FSNode *root = create_folder("root");

	FSNode *folder1 = create_folder("folder1");
	FSNode *file1 = create_file("file1.txt", 100);
	FSNode *file2 = create_file("file2.txt", 200);
	FSNode *folder2 = create_folder("folder2");
	FSNode *file3 = create_file("file3.txt", 300);

	add_child(root, folder1);
	add_child(root, file1);

	add_child(folder1, file2);
	add_child(folder1, folder2);

	add_child(folder2, file3);

	printf("Filesystem tree:\n");
	print_tree(root, 0);

	free_tree(root);

	return 0;
} */