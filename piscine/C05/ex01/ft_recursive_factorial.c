/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:39:30 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/21 09:55:40 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	result = nb * (ft_recursive_factorial(nb - 1));
	return (result);
}

/* int	main(void)
{
	int nb = 10;
	printf("%d\n", ft_recursive_factorial(nb));
	return (0);
} */