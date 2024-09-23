/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_part5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:36:24 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/25 22:14:00 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solve.h"
#include "lib_ft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define ONE_DIGIT	1
#define TWO_DIGITS	2
#define HUNDRED		3
#define THOUSAND	4

/**
 * Print the two digit number, currently pointed by nb:
 * if if starts with '1', or if the next digit is '0',
 * marks the next digit as ' ' (not needed to print,
 * BUT print the word of power of three tens, that comes next);
 *
 * otherwise, just prints the first digit of this two digit number.
 * @param dict	A dictionary to search in.
 * @param nb	A string with number.
 * @return	0, if everything went fine;
 * 			Some other positive value otherwise.
 */
int	ft_print_two_digits(const struct s_dict_entry *dict, char *nb)
{
	char	*two_digits_word;

	two_digits_word = ft_get_word_for_tens(dict, nb);
	if (two_digits_word == NULL)
		return (1);
	ft_print_word(two_digits_word);
	if (*nb == '1' || *(nb + 1) == '0')
		*(nb + 1) = ' ';
	return (0);
}

/**
 * Prints e.g. thousands, million, etc., depending on the length of nb.
 * @param dict	A dictionary to search in.
 * @param nb	A string with number.
 * @return	0, if everything went fine;
 * 			Some other positive value otherwise.
 */
int	ft_print_three_tens_power_word(const struct s_dict_entry *dict, char *nb)
{
	char	*three_tens_power_word;

	three_tens_power_word = ft_get_word_by_len(dict, nb);
	if (three_tens_power_word == NULL)
		return (1);
	ft_print_word(three_tens_power_word);
	return (0);
}

/**
 * Prints e.g. thousands, million, etc., depending on the length of nb.
 * @param dict	A dictionary to search in.
 * @param nb	A string with number.
 * @return	0, if everything went fine;
 * 			Some other positive value otherwise.
 */
int	ft_print_digit_and_word(const struct s_dict_entry *dict, char *nb)
{
	char	*digit_word;

	digit_word = ft_get_word_for_digit(dict, nb);
	if (digit_word == NULL && *nb != ' ')
		return (1);
	if (digit_word != NULL)
		ft_print_word(digit_word);
	if (ft_strlen(nb) >= THOUSAND)
	{
		if (*nb != ' ')
			(void) ft_fd_putchar(STDOUT_FILENO, ' ');
		if (ft_print_three_tens_power_word(dict, nb))
			return (1);
	}
	return (0);
}

/**
 * Print the number pointed by nb.
 * @param dict	A dictionary to search in.
 * @param nb	A string with number.
 * @return	0, if everything went fine;
 * 			Some other positive value otherwise.
 */
int	ft_print_words(const struct s_dict_entry *dict, char *nb)
{
	size_t	nb_len;

	nb_len = ft_strlen(nb);
	while (*nb != '\0' && nb_len >= 0)
	{
		if (*nb != '0' && (nb_len - 1) % 3 == HUNDRED - 1)
		{
			if (ft_print_hundreds(dict, nb))
				return (1);
		}
		else if (*nb != '0' && (nb_len - 1) % 3 == TWO_DIGITS - 1)
		{
			if (ft_print_two_digits(dict, nb))
				return (1);
		}
		else if (*nb != '0' && (nb_len - 1) % 3 == ONE_DIGIT - 1)
			if (ft_print_digit_and_word(dict, nb))
				return (1);
		nb++;
		nb_len--;
		if (*nb != '0' && nb_len && (*nb != ' ' || nb_len > TWO_DIGITS))
			(void) ft_fd_putchar(STDOUT_FILENO, ' ');
	}
	return (0);
}

#undef THOUSAND
#undef HUNDRED
#undef TWO_DIGITS
#undef ONE_DIGIT
