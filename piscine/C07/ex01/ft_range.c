/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:32:32 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/29 15:57:43 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;

	if (min >= max)
		return (NULL);
	i = 0;
	array = malloc((max - min) * sizeof(int));
	if (array == NULL)
		return (NULL);
	while (i + min < max)
	{
		array[i] = i + min;
		i++;
	}
	return (array);
}

/* int	main(void)
{
	int *array;
	int i;
	int min;
	int max;

	min = -20;
	max = -1;
	i = 0;
	array = ft_range(min, max);
	printf("Array:\n");
	while (i < (max - min))
	{
		printf("%d ", array[i]);
		i++;
	}
} */