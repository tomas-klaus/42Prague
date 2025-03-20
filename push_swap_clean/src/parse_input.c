/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:37:12 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/20 12:29:31 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
						+ 1] >= '0' && str[i + 1] <= '9') || str[i
					+ 1] == '\0'))
			return (0);
		i++;
	}
	arr = ft_split(str, ' ');
	count = count_arrays(arr);
	free_2d_array(arr);
	return (count);
}

/**
 * @brief Fills an array with parsed command line arguments
 */
int	fill_array(int *arr, int argc, char **argv)
{
	char	**arg_arr;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	while (i <= argc - 1)
	{
		j = 0;
		arg_arr = ft_split(argv[i], ' ');
		while (arg_arr[j])
		{
			if (check_overflow(arg_arr[j]))
				return (check_overflow(arg_arr[j]));
			arr[k] = ft_atoi(arg_arr[j]);
			j++;
			k++;
		}
		i++;
		free_2d_array(arg_arr);
	}
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
	while (i <= argc - 1)
	{
		count += check_and_count(argv[i]);
		if (!check_and_count(argv[i]))
			return (NULL);
		i++;
	}
	arr = malloc(count * sizeof(int));
	if (fill_array(arr, argc, argv) || map_ranks(arr, count))
	{
		free(arr);
		return (NULL);
	}
	*size = count;
	return (arr);
}
