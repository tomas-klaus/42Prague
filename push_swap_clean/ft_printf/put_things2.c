/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_things2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:33:30 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/17 17:12:30 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_base_long(unsigned long long n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n > 15)
		count += ft_putnbr_base_long(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	print_pointer(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	else
	{
		i += ft_putstr("0x");
		i += ft_putnbr_base_long(ptr);
		return (i);
	}
}
