/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:50:31 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 16:50:33 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
	struct Preferences *prefs = get_user_preferences();
	if (prefs == NULL)
		return (NULL);

	struct MovieList *movies = find_movies(prefs);
	if (movies == NULL)
	{
		free(prefs);
		return (NULL);
	}

	struct Plan *plan = build_plan(movies);
	if (plan == NULL)
	{
		free(movies);
		free(prefs);
		return (NULL);
	}
	return (plan);
}
