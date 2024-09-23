/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:51:44 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/21 09:57:51 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	result = nb * (ft_recursive_power(nb, power - 1));
	return (result);
}

/* int	main(void)
{
	int nb = 2;
	int power = 5;

	printf("%d\n", ft_recursive_power(nb, power));
	return (0);
} */