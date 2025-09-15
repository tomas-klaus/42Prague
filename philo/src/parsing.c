/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:03:21 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/15 19:55:50 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (SUCCESS);
	return (ERROR);
}

/**
 * Works as ordinary ft_atoi and returns an
 * error if the number is larger of smaller than int range.
 */
int	ft_safe_atoi(const char *str, int *error)
{
	long	res;
	int		positive;

	positive = 1;
	res = 0;
	*error = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			positive = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if ((res * positive) > 2147483647 || ((res * positive) < -2147483648))
			return (*error = 1, 0);
		str++;
	}
	if (*str != '\0')
		*error = 1;
	return ((int)(res * positive));
}

int	parse_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	error;

	i = 1;
	while (i < argc)
	{
		error = 0;
		j = 0;
		if (argv[i][j] == '\0' || (argv[i][j] == '-'))
			return (msg("Error: Invalid argument\n", ERROR));
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (msg("Error: Not a digit\n", ERROR));
			j++;
		}
		if (error)
			return (msg("Error: Int overflow\n", ERROR));
		if ((ft_safe_atoi(argv[i], &error)) <= 0 && i != 5)
			return (msg("Error: Argument has to be greater than 0\n", ERROR));
		i++;
	}
	return (SUCCESS);
}
