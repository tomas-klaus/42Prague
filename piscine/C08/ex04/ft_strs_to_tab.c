/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:34:41 by tklaus            #+#    #+#             */
/*   Updated: 2024/08/29 19:19:14 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int a;
	t_stock_str *ft_my_struct;

	a = 0;
	ft_my_struct = malloc((ac + 1) * sizeof(t_stock_str));
	while (a < ac)
	{
		ft_my_struct[a].size = ft_strlen(av[a]);
		ft_my_struct[a].str = malloc(ft_my_struct[a].size + 1);
		ft_strcpy(ft_my_struct[a].str, av[a]);
		ft_my_struct[a].copy = malloc(ft_my_struct[a].size + 1);
		ft_strcpy(ft_my_struct[a].copy, av[a]);
		a++;
	}
	ft_my_struct[a].str = NULL;
	return (ft_my_struct);
}