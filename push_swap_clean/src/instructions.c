/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:37:29 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/19 21:28:22 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	swap(t_list *stack)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	first = stack;
	second = first->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
}

void	pa(t_list **stack_to, t_list **stack_from)
{
	t_list	*to;
	t_list	*from;
	int		value;

	if (*stack_from == NULL)
		return ;
	from = *stack_from;
	value = from->content;
	to = ft_lstnew(value);
	ft_lstadd_front(stack_to, to);
	*stack_from = from->next;
	free(from);
	printf("pa\n");
}

void	pb(t_list **stack_from, t_list **stack_to)
{
	t_list	*to;
	t_list	*from;
	int		value;

	if (*stack_from == NULL)
		return ;
	from = *stack_from;
	value = from->content;
	to = ft_lstnew(value);
	ft_lstadd_front(stack_to, to);
	*stack_from = from->next;
	free(from);
	printf("pb\n");
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack);
	last->next = first;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_to_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = ft_lstlast(first);
	second_to_last = first;
	while (second_to_last->next != last)
	{
		second_to_last = second_to_last->next;
	}
	second_to_last->next = NULL;
	last->next = first;
	*stack = last;
}
