/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:49:35 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 16:49:36 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "average.h"

float	average(const int *arr, int size)
{
	int		i;
	float	av;

	i = 0;
	av = 0;
	while (i < size)
	{
		if (arr[i] <= 100)
			av += arr[i];
		else
			size--;
		i++;
	}
	return (av / size);
}
