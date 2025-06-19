/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:20:39 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 16:50:57 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "music_organizer.h"

void	free_mtx(char **mtx)
{
	int	i;

	i = 0;
	while (mtx && mtx[i] != NULL)
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}

struct MusicLibrary *organize_music_library(const char *directory_path)
{
	int					i;
	struct MusicLibrary	*lib = create_music_library();
	char				**dirs = scan_directory(directory_path);
	struct MusicFile	*file;

	i = 0;
	if (!dirs || !lib)
		return (NULL);
	while (dirs[i])
	{
		file = process_music_file(directory_path, dirs[i]);
		update_music_library(lib, file);
		free(file);
		i++;
	}
	free_mtx(dirs);
	return (lib);
}
