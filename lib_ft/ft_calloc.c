/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:40:47 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/23 12:05:09 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (ptr);
}
/* #include <stdio.h>
#include <stdlib.h>
int main() {
   int n = 5;
   int *array;
   
   // use calloc function to allocate the memory
   array = (int*)ft_calloc(n, sizeof(int));
   
   if (array == NULL) {
      fprintf(stderr, "Memory allocation failed!\n");
      return 1;
   }
   
   //Display the array value
   printf("Array elements after ft_calloc: ");
   for (int i = 0; i < n; i++) {
      printf("%d ", array[i]);
   }
   printf("\n");
   
   //free the allocated memory
   free(array);
   return 0;
} */