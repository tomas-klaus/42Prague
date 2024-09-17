/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:16:17 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/17 13:22:52 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;

	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	while (n > 0)
	{
		ptrdest[n - 1] = ptrsrc[n - 1];
		n--;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char buffer[20] = "abcdefgh";

	// Overlapping regions: copying 5 bytes starting from buffer[0] to buffer[3]
	ft_memmove(buffer + 3, buffer, 5);

	printf("Resulting buffer: %s\n", buffer);
	return (0);
} */