/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:28:27 by tklaus            #+#    #+#             */
/*   Updated: 2024/09/23 18:39:23 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	countsegments(char const *s, char c)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (s[i])
	{
		printf("%c", s[i]);
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

char **ft_split(char const *s, char c){
    char **arr;
    int count;
    
    count = countsegments(s, c);
    printf("%d\n",count);

    
    

    return arr;
}

int	main(void)
{
	char const s[] = "hello, im, going, to, 42, school";
	char c = ',';
	printf("hello");
	char **arr = ft_split(s, c);
	for (int i = 0; i < 6; i++)
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
	}
	free(arr);

	return (0);
}