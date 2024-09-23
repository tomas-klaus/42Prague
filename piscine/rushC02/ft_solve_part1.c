/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:36:24 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/27 13:26:13 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solve.h"
#include "lib_ft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Checks the number by same rules as atoi(), EXCEPT for sign:
 * numbers can't be negative in scope of our program.
 * @param nb	Number to check.
 * @return	0, if number is ok;
 * 			Some positive number otherwise.
 */
int	ft_check_nb(const char *nb)
{
	int	got_at_least_one_digit;

	got_at_least_one_digit = 0;
	while (ft_isspace(*nb))
		nb++;
	if (*nb == '+' || *nb == '-')
		if (*nb++ == '-')
			return (1);
	while (*nb != '\0')
	{
		if (!ft_isdigit(*nb++))
			return (1);
		got_at_least_one_digit = 1;
	}
	return (!got_at_least_one_digit);
}

/**
 * Skips spaces in s.
 * @param s	A pointer to string in which to skip spaces.
 */
void	ft_skip_spaces(const char **s)
{
	while (**s == ' ')
		*s += 1;
}

#define EMPTY_LINE 1

/**
 * Check basic rules of a dictionary entry. Those rules are:
 * [a number][0 to n spaces]:[0 to n spaces][any printable characters]\n
 * Line can also be empty. That's also fine :)
 * @param dict_entry	A line with dict entry.
 * @return	0, if looks good;
 * 			Some positive number otherwise.
 */
int	ft_dict_entry_check_rules(const char *dict_entry)
{
	int	got_key;
	int	got_value;

	got_key = 0;
	got_value = 0;
	if (ft_strlen(dict_entry) == EMPTY_LINE && *dict_entry == '\n')
		return (0);
	while (ft_isdigit(*dict_entry))
	{
		got_key = 1;
		dict_entry++;
	}
	ft_skip_spaces(&dict_entry);
	if (*dict_entry != ':')
		return (1);
	ft_skip_spaces(&dict_entry);
	while (ft_is_printable(*dict_entry))
	{
		got_value = 1;
		dict_entry++;
	}
	if (*dict_entry != '\n' || !(got_key && got_value))
		return (1);
	return (0);
}

#undef EMPTY_LINE

/**
 * Reads the key from dict_entry.
 * @param dict_entry	From where to read the key.
 * @return	A pointer to the dynamically allocated key;
 * 			NULL in case of some error.
 */
char	*ft_get_key(const char *dict_entry)
{
	char	*key;
	size_t	key_size;
	size_t	read_bytes;

	key = NULL;
	key_size = 0;
	read_bytes = 0;
	while (ft_isdigit(*dict_entry))
	{
		if (!(read_bytes + 1 < key_size))
		{
			if (ft_extend_str(&key, &key_size))
			{
				free(key);
				return (NULL);
			}
		}
		key[read_bytes++] = *dict_entry++;
	}
	key[read_bytes] = '\0';
	return (key);
}

/**
 * Skips key, [0 to n spaces], colon and [0 to n spaces].
 * @param dict_entry	A pointer to dict_entry (string) in which to skip those.
 */
void	ft_skip_dict_entry_until_value(const char **dict_entry)
{
	while (ft_isdigit(**dict_entry))
		*dict_entry += 1;
	ft_skip_spaces(dict_entry);
	if (**dict_entry == ':')
		*dict_entry += 1;
	ft_skip_spaces(dict_entry);
}
