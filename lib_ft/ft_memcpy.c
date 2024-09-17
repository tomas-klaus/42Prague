/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:14:35 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/17 12:15:17 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;

	i = 0;
	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
    return dest;
}
/* 
#include <stdio.h>
#include <string.h>

struct Point {
    int x, y;
};

int main() {
    struct Point p1 = {10, 20};
    struct Point p2;

    // Copy struct data from p1 to p2
    ft_memcpy(&p2, &p1, sizeof(struct Point));

    printf("p2.x = %d, p2.y = %d\n", p2.x, p2.y);
    return 0;
} */