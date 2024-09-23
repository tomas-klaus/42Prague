/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:10:13 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/21 11:02:39 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	result;

	result = 0;
	i = 0;
	minus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
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
	if (minus % 2 != 0)
		result *= -1;
	return (result);
}

/* int	main(void)
{
	char str[] = " --5-+--+1234ab567";

	printf("%d", ft_atoi(str));
	return (0);
} */