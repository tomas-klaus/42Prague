/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:40:47 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/26 15:27:59 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	result;
	void	*ptr;

	result = nmemb * size;
	if (result == 0)
		return (malloc(1));
	ptr = malloc(result);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, result);
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void) {
   char *str;
   str = (char *)ft_calloc(30, 1);
	if (!str)
		write(1, "NULL", 4);
	else
		write(1, str, 30);
   free(str);
} */