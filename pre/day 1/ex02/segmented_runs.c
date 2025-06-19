/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:50:07 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 16:50:14 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

bool check_seg(int start, int end, const int *arr)
{
	while (start < end)
	{
		if (arr[start] > arr[start + 1])
			return (false);
		start++;
	}
	return (true);
}

int count_segments(const int *arr, int size)
{
	int	i;
	int	segm_count;
	int	pos;

	pos = 0;
	i = 0;
	segm_count = 0;
	while (i < size)
	{
		pos = i;
		while (arr[i] != -1)
			i++;
		if (check_seg(pos, i - 1, arr))
			segm_count++;
		i++;
	}
	return(segm_count);
}
