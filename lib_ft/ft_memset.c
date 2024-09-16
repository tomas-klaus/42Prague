/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:49:05 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/16 17:01:59 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n){
   
    
    unsigned char *ptr = (unsigned char *)s;
    size_t i = 0;
    while (i < n) {
        ptr[i] = (unsigned char)c;
        i++;
    }
    return s;
}
/* 
#include <stdio.h>
#include <string.h>

int main() {
   char str[20];
   char str2[20];
   ft_memset(str, 'Z', 10);
   memset(str2, 'Z', 10);
   printf("String after memset(): %s\n", str);
   printf("String after memset(): %s\n", str2);
   return 0;
} */