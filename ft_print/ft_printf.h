/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:09:29 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/17 17:10:25 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	format_check(char specifier, va_list args);
int	parse_args(const char *str, va_list args, int count);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbr_base(unsigned int n, char specifier);
int	ft_printf(const char *str, ...);
int	print_pointer(unsigned long long n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_base_long(unsigned long long n);

#endif