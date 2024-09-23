/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:03:09 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/22 15:46:01 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	*range = malloc((max - min) * sizeof(int));
	while (i + min < max)
	{
		(*range)[i] = i + min;
		i++;
	}
	return (max - min);
}

/* int	main(void)
{
	int	*array;
	int	i;
	int	min;
	int	max;
	int	result;

	array = NULL;
	min = -30;
	max = -10;
	i = 0;
	result = ft_ultimate_range(&array, min, max);
	printf("Array:\n");
	while (i < (max - min))
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("Result is: %d\n", result);
}
 */