/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:50:23 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/09/26 19:08:47 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. see if the n is negative, get the length(number of digits) of the int
2. allocate corresponding space for string
3. write the last digit of n by dividing
	% by 10 and assign to the last position in string
4. crop the last digit of n by dividing / by ten
 */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	getlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	assignstr(int n, int minus, int len, char *str)
{
	int	i;

	i = len - 1;
	if (n < 0)
		n = -n;
	while (i >= 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (minus)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int		minus;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = getlen(n);
	minus = (n < 0);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
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