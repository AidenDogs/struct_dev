/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:49:44 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 16:49:47 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "first_last.h"

void first_last(int arr[], int size, int target, int *first, int *last)
{
	int	i;
	int j;

	i = 0;
	j = size - 1;
	*first = -1;
	*last = -1;
	while (i <= size)
	{
		if (arr[i] == target)
		{
			*last = i;
		}
		if (arr[j] == target)
		{
			*first = j;
		}
		i++;
		j--;
	}
	if (*first == *last)
		*last = -1;
}

int	main()
{
	int first;
	int last;

	first = -1;
	last = -1;
	int arr[] = {1, 2, 1, 3, 1};
	first_last(arr, 4, 1, &first, &last);
	printf("first: %d\n", first);
	printf("last: %d\n", last);
	return (0);
}
