/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:37:29 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/16 11:18:41 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
swap
the first node is t_list stack_a
the second node is stack_a->next
make int tmp_value and store first->value
first->value = second->value
second->value = tmp_value
	sa
	sb
	ss

push
basically just make a new node in stack_b
and assign the value of the stack_a first node and delete it (and free?)
make the first->next the new first (first = first->next)
	pa
	pb

rotate (first element becomes last)
store the first->value int temp
make the first->next the new first (first = first->next)
delete the first and free?
add a new node to the back of the list and paste the value from temp (ft_lst_addback)
	ra
	rb
	rr
reverse rotate(last element becomes first)
	rra
	rrb
	rrr
*/

#include "../include/header.h"

void swap(t_list *stack)
{
	t_list *first;
	t_list *second;
	int temp;

	if (stack == NULL || stack->next == NULL)
		return;

	first = stack;
	second = first->next;

	temp = first->content;
	first->content = second->content;
	second->content = temp;
}

void pa(t_list **stack_to, t_list **stack_from)
{
	t_list *to;
	t_list *from;
	int value;

	if (*stack_from == NULL)
		return;

	from = *stack_from;
	value = from->content;
	to = ft_lstnew(value);
	ft_lstadd_front(stack_to, to);

	*stack_from = from->next;
	free(from);
	printf("pa\n");
}

void pb(t_list **stack_from, t_list **stack_to)
{
	t_list *to;
	t_list *from;
	int value;

	if (*stack_from == NULL)
		return;

	from = *stack_from;
	value = from->content;
	to = ft_lstnew(value);
	ft_lstadd_front(stack_to, to);

	*stack_from = from->next;
	free(from);
	printf("pb\n");
}

void rotate(t_list **stack)
{
	t_list *first;
	t_list *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	*stack = first->next;
	first->next = NULL;

	last = ft_lstlast(*stack);
	last->next = first;
}

void reverse_rotate(t_list **stack)
{
	t_list *first;
	t_list *last;
	t_list *second_to_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	last = ft_lstlast(first);

	// Find the second-to-last node
	second_to_last = first;
	while (second_to_last->next != last)
	{
		second_to_last = second_to_last->next;
	}

	// Move the last node to the front
	second_to_last->next = NULL;
	last->next = first;
	*stack = last;
}
