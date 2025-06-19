/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:50:34 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 16:50:42 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIE_PLANNER_H
# define MOVIE_PLANNER_H

#include <stdlib.h>

struct Preferences;
struct MovieList;
struct Plan;

struct Preferences	*get_user_preferences(void);
struct MovieList	*find_movies(struct Preferences *prefs);
struct Plan			*build_plan(struct MovieList *list);
struct Plan			*create_movie_night_plan(void);

#endif