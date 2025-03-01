/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:51 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/02/28 23:27:52 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
function	parse_input(arguments):
	validate arguments (check for duplicates, non-numeric, etc.)
	convert to integers
	store in stack A

initialize stack A with parsed numbers
initialize empty stack B

implement sorting operations (sa, sb, ra ...)

handle small cases (2,3,4,5)

sorting alghorithm

optimize moves

output operations
 */

#include "header.h"

int	main(int argc, char **argv)
{
	int *arr;
	if (argc < 2)
	{
		printf("No arguments provided\n");
		return (1);
	}

	arr = parse_input(argc, argv);

	if (!arr)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		int i = 0;
		while (i < 8)
		{
			printf("%d ", arr[i]);
			i++;
		}
	}

	free(arr);

	return (0);
}