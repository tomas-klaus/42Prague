/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:44:17 by kluas             #+#    #+#             */
/*   Updated: 2024/08/20 09:17:42 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	hex[2];

	while (*str != '\0')
	{
		if (!(*str >= 32 && *str <= '~'))
		{
			write(1, "\\", 1);
			hex[0] = "0123456789abcdef"[((unsigned char)*str / 16)];
			hex[1] = "0123456789abcdef"[((unsigned char)*str % 16)];
			write(1, &hex[0], 1);
			write(1, &hex[1], 1);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}

/* int	main(void)
{
	char	str[] = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(str);
	return (0);
} */
