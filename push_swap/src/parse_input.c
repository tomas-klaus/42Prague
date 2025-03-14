/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:37:12 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/14 18:36:51 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
i need a loop that cycles through the whole string or the args, checks for any
unwanted characters and converts all the characters to ints and stores them in an array
which is then sorted and the original values are replaced with their ranks in the sorted array
*/

#include "../include/header.h"

int	check_and_count(char *str)
{
	int		i;
	int		count;
	char	**arr;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '-'
				|| str[i] == '+'))
			return (0);
		if ((str[i] == '+' || str[i] == '-') && !(str[i + 1] >= '0' && str[i
				+ 1] <= '9'))
			return (0);
		if ((str[i] >= '0' && str[i] <= '9') && !(str[i + 1] == ' ' || (str[i
					+ 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == '\0'))
			return (0);
		i++;
	}
	arr = ft_split(str, ' ');
	count = count_arrays(arr);
	free(arr);
	return (count);
}

/**
 * @brief Fills an array with parsed command line arguments
 */
int	fill_array(int **arr, int argc, char **argv, int count)
{
	char	**arg_arr;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	*arr = malloc(count * sizeof(int));
	if (!(*arr))
		return (1);
	while (i <= argc - 1)
	{
		j = 0;
		arg_arr = ft_split(argv[i], ' ');
		while (arg_arr[j])
		{
			if (check_overflow(arg_arr[j]))
				return (1);
			(*arr)[k] = ft_atoi(arg_arr[j]);
			printf("%d ", (*arr)[k]);
			j++;
			k++;
		}
		i++;
	}
	printf("\n");
	return (0);
}

void	map(int count, int *arr, int *sorted_arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (arr[i] == sorted_arr[j])
			{
				arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	map_ranks(int *arr, int count)
{
	int	*sorted_arr;
	int	i;

	sorted_arr = malloc(count * sizeof(int));
	if (!sorted_arr)
		return (1);
	i = 0;
	while (i < count)
	{
		sorted_arr[i] = arr[i];
		i++;
	}
	if (ft_sort(sorted_arr, count))
	{
		printf("Error: duplicate numbers\n");
		free(sorted_arr);
		return (1);
	}
	map(count, arr, sorted_arr);
	free(sorted_arr);
	return (0);
}

int	*parse_input(int argc, char **argv, int *size)
{
	int	i;
	int	count;
	int	*arr;

	count = 0;
	i = 1;
	printf("Number of arguments: %d\n", argc);
	while (i <= argc - 1)
	{
		count += check_and_count(argv[i]);
		if (!check_and_count(argv[i]))
		{
			printf("Error: invalid character\n");
			return (NULL);
		}
		i++;
	}
	printf("size: %d\n", count);
	arr = malloc(count * sizeof(int));
	if (fill_array(&arr, argc, argv, count))
	{
		return (NULL);
	}
	if (map_ranks(arr, count))
		return (NULL);
	*size = count;
	return (arr);
}
