/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:09:41 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/14 16:07:10 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"


/* int	has_duplicates(int *arr, int count)
{
int	i;

i = 0;
while (i < count - 1)
{
    if (arr[i] == arr[i + 1])
        return (1);
    i++;
}
return (0);
} */

int	ft_sort(int *sorted_arr, int count)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (sorted_arr[j] > sorted_arr[j + 1])
			{
				temp = sorted_arr[j];
				sorted_arr[j] = sorted_arr[j + 1];
				sorted_arr[j + 1] = temp;
			}
            else if (sorted_arr[j] == sorted_arr[j + 1])
                return (1);
			j++;
		}
		i++;
	}
    i = 0;
   return (0);
}




int	count_arrays(char **arr)
{
	int	count;

	count = 0;
	while (arr[count] != NULL)
	{
		count++;
	}
	return (count);
}
int check_overflow(char *str)
{
    int i;
    int minus;
    long long result;

    if (!str)
        return (0);
    result = 0;
    i = 0;
    minus = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            minus++;
        i++;
    }
    while ((str[i] >= 48 && str[i] <= 57))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (minus)
        result *= -1;
    if (result > 2147483647 || result < -2147483648)
        return (1);
    return (0);
}
