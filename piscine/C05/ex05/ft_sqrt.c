/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:03:22 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/22 15:23:27 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 2;
	if (nb == 1)
		return (1);
	while (i * i != nb)
	{
		if (i * i > nb)
		{
			return (0);
		}
		i++;
	}
	return (i);
}

/* int	main(void)
{
	printf("%d\n", ft_sqrt(9));

	return (0);
} */