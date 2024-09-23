/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_part4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:36:24 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/25 21:59:05 by asagymba         ###   ########.fr       */
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
 * Searches for the word for the first digit in nb.
 * @param dict	A dictionary to search in.
 * @param nb	A string with number.
 * @return	A pointer to found value;
 * 			NULL if not defined in dictionary.
 */
char	*ft_get_word_for_digit(const struct s_dict_entry *dict, char *nb)
{
	while (dict != NULL)
	{
		if (ft_strlen(dict->key) == ONE_DIGIT && *(dict->key) == *nb)
			return (dict->value);
		dict = dict->next;
	}
	return (NULL);
}

/**
 * Searches for the word for current ten number (e.g. 12, 25, etc.)
 * @param dict	A dictionary to search in.
 * @param nb	A string with number.
 * @return	A pointer to found value;
 * 			NULL if not defined in dictionary.
 */
char	*ft_get_word_for_tens(const struct s_dict_entry *dict, char *nb)
{
	while (dict != NULL)
	{
		if (*nb == '1')
		{
			if (ft_strncmp(dict->key, nb, TWO_DIGITS) == 0)
				return (dict->value);
		}
		else
		{
			if (ft_strlen(dict->key) == TWO_DIGITS && *(dict->key) == *nb)
				return (dict->value);
		}
		dict = dict->next;
	}
	return (NULL);
}

/**
 * Searches for the word, which has key of the same size as nb.
 * @param dict	A dictionary to search in.
 * @param nb	A string with number.
 * @return	A pointer to found value;
 * 			NULL if not defined in dictionary.
 */
char	*ft_get_word_by_len(const struct s_dict_entry *dict, char *nb)
{
	size_t	nb_len;

	nb_len = ft_strlen(nb);
	while (dict != NULL)
	{
		if (ft_strlen(dict->key) == nb_len)
			return (dict->value);
		dict = dict->next;
	}
	return (NULL);
}

#define OUT	0
#define IN	1

/**
 * Prints word and trims multiple spaces.
 * @param word	A word to print, which trimming multiple consequent spaces.
 */
void	ft_print_word(const char *word)
{
	int	space_state;

	space_state = OUT;
	while (*word != '\0')
	{
		if (*word == ' ')
		{
			if (space_state == OUT)
				(void) ft_fd_putchar(STDOUT_FILENO, ' ');
			space_state = IN;
		}
		else
		{
			(void) ft_fd_putchar(STDOUT_FILENO, *word);
			space_state = OUT;
		}
		word++;
	}
}

#undef IN
#undef OUT

/**
 * Prints amount of hundreds (by the definition provided in dictionary),
 * and later the the hundred itself (the same way: by the definition
 * provided in dictionary).
 *
 * If the next two digits are '0', marks the third digit as ' '
 * (please see comment for ft_print_two_digits() for this one).
 * @param dict	A dictionary to search in.
 * @param nb	A string with number.
 * @return	0, if everything went fine;
 * 			Some other positive value otherwise.
 */
int	ft_print_hundreds(const struct s_dict_entry *dict, char *nb)
{
	char	*digit_word;
	char	*hundred_word;

	digit_word = ft_get_word_for_digit(dict, nb);
	hundred_word = ft_get_word_by_len(dict, "666");
	if (digit_word == NULL || hundred_word == NULL)
		return (1);
	ft_print_word(digit_word);
	(void) ft_fd_putchar(STDOUT_FILENO, ' ');
	ft_print_word(hundred_word);
	if (*(nb + ONE_DIGIT) == '0' && (*(nb + TWO_DIGITS) == '0'))
		*(nb + TWO_DIGITS) = ' ';
	return (0);
}

#undef THOUSAND
#undef HUNDRED
#undef TWO_DIGITS
#undef ONE_DIGIT
