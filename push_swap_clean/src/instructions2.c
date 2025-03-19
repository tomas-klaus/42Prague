/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:44:52 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/19 21:21:28 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	sa(t_list **stack_a)
{
	swap(*stack_a);
	printf("sa\n");
}

void	sb(t_list **stack_b)
{
	swap(*stack_b);
	printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}

void	ra(t_list **stack)
{
	rotate(stack);
	printf("ra\n");
}

void	rb(t_list **stack)
{
	rotate(stack);
	printf("rb\n");
}
