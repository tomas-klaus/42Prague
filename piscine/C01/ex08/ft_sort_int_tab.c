/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:47:46 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/08 17:33:38 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	f;
	int	help;
	int	sorted;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		f = 0;
		while (f < (size - 1))
		{
			if (tab[f] > tab[f + 1])
			{
				help = tab[f];
				tab[f] = tab[f + 1];
				tab[f + 1] = help;
				sorted = 0;
			}
			f++;
		}
	}
}
