/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_part3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:36:24 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/25 21:31:26 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solve.h"
#include "lib_ft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define ONE_DIGIT 1
#define TWO_DIGITS 2
#define HUNDRED 3
#define THOUSAND 4

/**
 * Checks if key in entry is one of the following:
 * 0 - 19, 20, 30, ..., 100, 1000, 1000000, 1000000000, ...
 * @return	1, if it is;
 * 			0 otherwise.
 */
int	ft_s_dict_entry_key_is_good(struct s_dict_entry *entry)
{
	int	keylen;

	if (entry == NULL || entry->key == NULL)
		return (0);
	keylen = ft_strlen(entry->key);
	if (keylen == ONE_DIGIT)
		return (1);
	if (keylen != TWO_DIGITS && entry->key[0] != '1')
		return (0);
	if (keylen == TWO_DIGITS)
	{
		if (entry->key[0] == '1' || (entry->key[0] != '0'
				&& ft_all_chars_in_str_are_zeroes(entry->key + 1)))
			return (1);
		return (0);
	}
	if ((keylen != HUNDRED && keylen != THOUSAND && (keylen - 1) % 3 != 0)
		|| !ft_all_chars_in_str_are_zeroes(entry->key + 1))
		return (0);
	return (1);
}

#undef THOUSAND
#undef HUNDREN
#undef TWO_DIGITS
#undef ONE_DIGIT

/**
 * Appends next_node to root.
 * @param root		Root of s_dict_entry.
 * @param next_node	Node to append.
 * @return A pointer to root.
 */
struct s_dict_entry	*ft_s_dict_entry_append(struct s_dict_entry *root,
		struct s_dict_entry *next_node)
{
	struct s_dict_entry	*node;

	if (root == NULL)
		return (next_node);
	node = root;
	while (node->next != NULL)
		node = node->next;
	node->next = next_node;
	return (root);
}

/**
 * In this function, I willingly don't check if the return value
 * of ft_prepare_next_dict_node() is -1, for the sake of Norminette.
 *
 * Parses the dictionary and returns the list of s_dick_entry's.
 * Please note, that only the entries with the following keys will be parsed:
 * 0 - 19, 20, 30, ..., 100, 1000, 1000000, 1000000000, ...
 * @param dict_file_name	File name of a dictionary.
 * @return	A list of parsed dictionary entries.
 * 			May be NULL, if dictionary is empty, or if caught some error.
 */
struct s_dict_entry	*ft_parse_dict(const char *dict_file_name)
{
	struct s_dict_entry	*retval;
	struct s_dict_entry	*next_val;
	int					fd;
	int					status;

	retval = NULL;
	fd = open(dict_file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (42)
	{
		status = ft_prepare_next_dict_node(&next_val, fd);
		if (!ft_s_dict_entry_key_is_good(next_val) && status != 1)
		{
			free(next_val->key);
			free(next_val->value);
			free(next_val);
			continue ;
		}
		retval = ft_s_dict_entry_append(retval, next_val);
		if (status == 1)
			break ;
	}
	(void)close(fd);
	return (retval);
}

/**
 * Skips zeroes in nb.
 * @param nb	A pointer to string.
 */
void	ft_skip_zeroes(const char **nb)
{
	while (**nb == '0')
		*nb += 1;
}

/**
 * Finds the biggest len of keys, available in dict.
 * @param dict	A dictionary to look into.
 * @return	A biggest len of available keys.
 *			If dict is empty, returns 0.
 */
size_t	ft_get_biggest_key_len(const struct s_dict_entry *dict)
{
	size_t	max;
	size_t	current_node_key_len;

	max = 0;
	while (dict != NULL)
	{
		current_node_key_len = ft_strlen(dict->key);
		if (!(current_node_key_len < max))
		{
			max = current_node_key_len;
		}
		dict = dict->next;
	}
	return (max);
}
