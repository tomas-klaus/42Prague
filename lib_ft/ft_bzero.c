/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:02:08 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/16 17:13:06 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/* 
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char buffer2[10];

    // Fill the buffer with non-zero data
    for (int i = 0; i < 10; i++) {
        buffer[i] = 'A';
        buffer2[i]= 'A';
    }

    // Use bzero to zero out the first 5 bytes of the buffer
    bzero(buffer, 5);
    ft_bzero(buffer2,5);

    // Print the buffer after using bzero
    for (int i = 0; i < 10; i++) {
        printf("%c ", buffer[i]);  // Non-zero will be 65 ('A'), zeros will be 0
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%c ", buffer2[i]);  // Non-zero will be 65 ('A'), zeros will be 0
    }

    

    return 0;
} */
