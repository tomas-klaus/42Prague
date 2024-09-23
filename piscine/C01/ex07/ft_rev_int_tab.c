/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:15:49 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/08 17:33:54 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	l;
	int	help;
	int	f;

	f = 0;
	l = size - 1;
	while (f < l)
	{
		help = tab[f];
		tab[f] = tab[l];
		tab[l] = help;
		f++;
		l--;
	}
}
