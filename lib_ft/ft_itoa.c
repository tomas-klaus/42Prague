/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:50:23 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/09/25 13:02:50 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. see if the n is negative, get the length(number of digits) of the int
2. allocate corresponding space for string
3. write the last digit of n by dividing
	% by 10 and assign to the last position in string
4. crop the last digit of n by dividing / by ten
 */

#include <stdio.h>
#include <stdlib.h>

int	getlen(int n)
{
	int	len;
	int	i;

	len = 0;
	i = n;
	if (i < 0)
		i = i * (-1);
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

void	assignstr(int n, int minus, int len, char *str)
{
	int	i;

	i = len;
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (minus)
	{
		str[0] = '-';
	}
}

char	*ft_itoa(int n)
{
	int		minus;
	int		len;
	char	*str;

	if (n == 0)
		return ("0");
	minus = 0;
	len = getlen(n);
	if (n < 0)
	{
		n = n * (-1);
		minus = 1;
		len++;
	}
	str = malloc((len + 1) * sizeof(char));
	assignstr(n, minus, len, str);
	return (str);
}

/* int	main(void)
{
	int i = 1000;
	char *c = ft_itoa(i);
	printf("result: %s", c);
	return (0);
} */