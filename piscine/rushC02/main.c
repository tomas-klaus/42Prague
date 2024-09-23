/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:40:45 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/25 18:00:37 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lib_ft.h"
#include "ft_solve.h"

/**
 * Error messages.
 */
#define GENERIC_ERROR	"Error\n"
#define DICT_ERROR		"Dict Error\n"

/**
 * Range of possible argc values.
 */
#define MIN_ARGC	2
#define MAX_ARGC	3

int	main(int argc, char **argv)
{
	const char	*file_name = "numbers.dict";
	char		*nb;

	if (!(argc >= MIN_ARGC && argc <= MAX_ARGC))
	{
		(void) ft_fd_putstr(STDERR_FILENO, GENERIC_ERROR);
		return (1);
	}
	if (argc == MAX_ARGC)
		file_name = *(++argv);
	nb = *(++argv);
	if (ft_check_nb(nb) != 0)
	{
		(void) ft_fd_putstr(STDERR_FILENO, GENERIC_ERROR);
		return (1);
	}
	if (ft_solve(file_name, nb))
	{
		(void) ft_fd_putstr(STDERR_FILENO, DICT_ERROR);
		return (1);
	}
	return (0);
}

#undef MAX_ARGC
#undef MIN_ARGC

#undef DICT_ERROR
#undef GENERIC_ERROR
