/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:20:31 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 16:51:27 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUSIC_ORGANIZER_H
# define MUSIC_ORGANIZER_H

# include <stdlib.h>

typedef struct MusicLibrary;
typedef struct MusicFile;

struct MusicLibrary	*create_music_library();
const char			**scan_directory(const char *directory_path);
struct MusicFile	*process_music_file(const char *directory_path, const char *filename);
void				update_music_library(struct MusicLibrary *library, struct MusicFile *song);
struct MusicLibrary	*organize_music_library(const char *directory_path);

#endif