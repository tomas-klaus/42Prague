/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:04:47 by kluas             #+#    #+#             */
/*   Updated: 2024/08/21 10:24:52 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kluas <kluas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:49:31 by kluas             #+#    #+#             */
/*   Updated: 2024/08/17 10:03:47 by kluas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	i = 0;
	while (*src != '\0' && i < nb)
	{
		dest[j] = *src;
		src++;
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

/* int	main(void)
{
	char dest[20] = "Hello, ";

	char src[] = "World!";

	

	printf("%s\n", ft_strncat(dest, src, 3));

	return (0);
} */