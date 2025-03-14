/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:22:48 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/14 17:47:14 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

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
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	fill_stack(stack_a, arr, size);
	return (0);
}
