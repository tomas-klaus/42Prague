/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:22:48 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/20 12:40:44 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	is_sorted(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
	*stack = NULL;
	free(stack);
}

void	print_stack(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current != NULL)
	{
		ft_printf("%d ", current->content);
		current = current->next;
	}
	ft_printf("\n");
}

void	fill_stack(t_list **stack_a, int *arr, int size)
{
	t_list	*new_node;
	int		i;

	i = 0;
	while (i < size)
	{
		new_node = ft_lstnew(arr[i]);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
}

int	init_stack(t_list **stack_a, t_list **stack_b, int *arr, int size)
{
	*stack_a = NULL;
	*stack_b = NULL;
	fill_stack(stack_a, arr, size);
	return (0);
}
