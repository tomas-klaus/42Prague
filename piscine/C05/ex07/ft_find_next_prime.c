/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:26:56 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/21 09:57:24 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_next_prime(int nb)
{
	int	i;
	int	found;

	found = 0;
	i = 2;
	if (nb <= 0 || nb == 1 || nb == 2)
	{
		return (2);
	}
	while (i < nb)
	{
		if (nb % i == 0)
		{
			nb++;
			i = 2;
		}
		i++;
		found = i;
	}
	return (found);
}

/* int	main(void)
{
	printf("%d\n", ft_find_next_prime(1500));
	return (0);
} */