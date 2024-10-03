/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:40:47 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/03 14:53:45 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	result;
	void	*ptr;

	result = nmemb * size;
	if (result == 0)
		result = 1;
	ptr = malloc(result);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, result);
	return (ptr);
}
/* #include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{

	void *ptr1 = calloc(0, 10);
	if (ptr1 == NULL)
		printf("calloc(0, 1) returned NULL\n");
	else
	{
		printf("calloc(0, 1) returned non-NULL\n");
		free(ptr1);
	}

	void *ptr2 = calloc(1, 0);
	if (ptr2 == NULL)
		printf("calloc(1, 0) returned NULL\n");
	else
	{
		printf("calloc(1, 0) returned non-NULL\n");
		free(ptr2);
	}

	void *ft_ptr1 = ft_calloc(0, 10);
	if (ft_ptr1 == NULL)
		printf("ft_calloc(0, 1) returned NULL\n");
	else
	{
		printf("ft_calloc(0, 1) returned non-NULL\n");
		free(ft_ptr1);
	}

	void *ft_ptr2 = ft_calloc(1, 0);
	if (ft_ptr2 == NULL)
		printf("ft_calloc(1, 0) returned NULL\n");
	else
	{
		printf("ft_calloc(1, 0) returned non-NULL\n");
		free(ft_ptr2);
	}
	return (0);
} */