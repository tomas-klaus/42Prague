/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:36:24 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/25 21:28:46 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solve.h"
#include "lib_ft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Get the value for the dictionary entry, after key is parsed.
 * @param dict_entry	A line with the dictionary entry.
 * @return	A pointer to parsed value or NULL in case of some error.
 */
char	*ft_get_value(const char *dict_entry)
{
	char	*value;
	size_t	value_size;
	size_t	read_bytes;

	value = NULL;
	value_size = 0;
	read_bytes = 0;
	while (*dict_entry != '\n' && *dict_entry != '\0')
	{
		if (!(read_bytes + 1 < value_size))
		{
			if (ft_extend_str(&value, &value_size))
			{
				free(value);
				return (NULL);
			}
		}
		value[read_bytes++] = *dict_entry++;
	}
	value[read_bytes] = '\0';
	return (value);
}

#define EMPTY_LINE 1

/**
 * Parses node from "dict_entry".
 * @param dict_entry	Dict entry to parse.
 * @return	A pointer to parsed node or NULL in case of some error.
 */
struct s_dict_entry	*ft_parse_node(const char *dict_entry)
{
	struct s_dict_entry	*retval;

	if (ft_strlen(dict_entry) == EMPTY_LINE && *dict_entry == '\n')
		return (NULL);
	retval = (struct s_dict_entry *)malloc(sizeof(struct s_dict_entry));
	retval->next = NULL;
	retval->key = ft_get_key(dict_entry);
	if (retval->key == NULL)
	{
		free(retval);
		return (NULL);
	}
	ft_skip_dict_entry_until_value(&dict_entry);
	retval->value = ft_get_value(dict_entry);
	if (retval->value == NULL)
	{
		free(retval->key);
		free(retval);
		return (NULL);
	}
	return (retval);
}

#undef EMPTY_LINE

/**
 * Prepare next dict node.
 * Parses it from opened file, whose file descriptor is provided in fd.
 * If line is empty or fd is over, *next_node will be set to NULL.
 * @param next_node	Where to save the next node.
 * @param fd		Opened file to read next node from.
 * @eeturn	0, if everything went ok;
 * 			1, if fd is over.
 * 			-1 in case of some error.
 */
int	ft_prepare_next_dict_node(struct s_dict_entry **next_node, int fd)
{
	char	*line;
	size_t	line_size;

	line = NULL;
	line_size = 0;
	if (ft_fd_getline(&line, &line_size, fd) == -1)
	{
		free(line);
		return (-1);
	}
	if (!ft_strlen(line))
	{
		*next_node = NULL;
		free(line);
		return (1);
	}
	if (ft_dict_entry_check_rules(line))
	{
		free(line);
		return (-1);
	}
	*next_node = ft_parse_node(line);
	free(line);
	return (0);
}

/**
 * Free list.
 * @param root	A root of the list.
 */
void	ft_free_s_dict_entry_list(struct s_dict_entry *root)
{
	struct s_dict_entry	*node;
	struct s_dict_entry	*next_node;

	node = root;
	while (node != NULL)
	{
		next_node = node->next;
		free(node->key);
		free(node->value);
		free(node);
		node = next_node;
	}
}

/**
 * Check if all characters in str are zero or not.
 * @param str	A string.
 * @return	1, if yes;
 * 			0 otherwise.
 */
int	ft_all_chars_in_str_are_zeroes(const char *str)
{
	while (*str != '\0')
		if (*str++ != '0')
			return (0);
	return (1);
}
