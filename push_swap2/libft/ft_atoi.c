/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:23:54 by tklaus            #+#    #+#             */
/*   Updated: 2025/02/28 22:48:33 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	minus;
	int	result;

	if (!nptr)
		return (0);
	result = 0;
	i = 0;
	minus = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus++;
		i++;
	}
	while ((nptr[i] >= 48 && nptr[i] <= 57))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (minus)
		result *= -1;
	return (result);
}

/* #include <stdio.h>

void	test_ft_atoi(const char *str, int expected)
{
	int	result;

	result = ft_atoi(str);
	if (result == expected)
		printf("Test passed for input \"%s\"\n", str);
	else
		printf("Test failed for input \"%s\": expected %d, got %d\n", str,
			expected, result);
}

int	main(void)
{
	test_ft_atoi("42", 42);
	test_ft_atoi("   -42", -42);
	test_ft_atoi("   +42", 42);
	test_ft_atoi("   0042", 42);
	test_ft_atoi("   -0042", -42);
	test_ft_atoi("2147483647", 2147483647);
	test_ft_atoi("-2147483648", -2147483648);
	test_ft_atoi("   +2147483647", 2147483647);
	test_ft_atoi("   -2147483648", -2147483648);
	test_ft_atoi("0", 0);
	test_ft_atoi("   0", 0);
	test_ft_atoi("   -0", 0);
	test_ft_atoi("123abc", 123);
	test_ft_atoi("abc123", 0);
	test_ft_atoi("", 0);
	test_ft_atoi("   ", 0);
	test_ft_atoi(NULL, 0);

printf("atoi: %d\n",atoi(NULL));
	return (0);
} */