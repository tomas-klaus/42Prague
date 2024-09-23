/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_part6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:36:24 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/25 21:33:43 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solve.h"
#include "lib_ft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Solve the rush-02.
 * @param dict_file_name	File name of a dictionary.
 * @param nb				Number to write as words.
 * @return	0, if everything went fine;
 * 			Some positive value otherwise.
 */
int	ft_solve(const char *dict_file_name, char *nb)
{
	struct s_dict_entry	*dict;
	int					status;

	dict = ft_parse_dict(dict_file_name);
	if (dict == NULL)
		return (1);
	ft_skip_spaces((const char **) &nb);
	ft_skip_zeroes((const char **) &nb);
	status = 0;
	if (*nb == '\0')
	{
		(void) ft_fd_putstr(STDOUT_FILENO, ft_get_word_for_digit(dict, "0"));
		(void) ft_fd_putchar(STDOUT_FILENO, '\n');
	}
	else
	{
		status = ft_print_words(dict, nb);
		if (!status)
			(void) ft_fd_putchar(STDOUT_FILENO, '\n');
	}
	ft_free_s_dict_entry_list(dict);
	return (status);
}
