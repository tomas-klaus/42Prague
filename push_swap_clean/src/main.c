/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:51 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/19 21:25:12 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
function	parse_input(arguments):
	validate arguments (check for duplicates, non-numeric, etc.)
	convert to integers
	map ranks

initialize stack A with parsed numbers
initialize empty stack B

check if stack A is sorted
sort stack
	if handle small cases (2,3,4,5)
		sort2 (only sa)
		sort3
		sort4
		sort5
	else use quicksort

optimize moves

output operations

--------------------------------------------------------------
implement sorting operations (sa, sb, ra ...)

sorting alghorithm QUICKSORT
	choose a pivot (middle between the biggest and smallest number)
	push smaller numbers to stack B
	after splitting the stack, make a pivot again and repeat the process
	until there are 3 or less numbers in stack A
	sort the remaining numbers in stack A
	push the numbers back to stack A in the correct order
 */

#include "../include/header.h"

int	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

void	free_int_2d_array(int **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b, int size)
{
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return ;
	}
	if (size <= 5)
		simple_sort(stack_a, stack_b, size);
	else
		turk_sort(stack_a, stack_b, size);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	int		size;
	int		*arr;
	t_list	**stack_a;
	t_list	**stack_b;

	size = 0;
	if (argc < 2)
	{
		return (1);
	}
	arr = parse_input(argc, argv, &size);
	if (!arr)
	{
		printf("Error\n");
		return (1);
	}
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	init_stack(stack_a, stack_b, arr, size);
	free(arr);
	sort_stack(stack_a, stack_b, size);
	return (0);
}
