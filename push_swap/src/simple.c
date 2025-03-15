/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:55:58 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/15 21:41:01 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int is_sorted(t_list **stack)
{
    t_list *current;

    current = *stack;
    while (current->next != NULL)
    {
        if (current->content > current->next->content)
            return (0);
        current = current->next;
    }
    return (1);
}

void sort2(t_list **stack)
{
    sa(stack);
}

void sort3(t_list **stack)
{
    int x = (*stack)->content;
    int y = (*stack)->next->content;
    int z = (*stack)->next->next->content;

    if (x < y && y > z && z > x)
    {
        sa(stack);
        ra(stack);
    }
    else if (x < y && y > z && z < x)
        rra(stack);
    else if (x > y && y < z && z > x)
        sa(stack);
    else if (x > y && y < z && z < x)
        ra(stack);
    else if (x > y && y > z && z < x)
    {
        sa(stack);
        rra(stack);
    }
}
/* 
find smallest number in stack A
rotate the most efficient way to get the smallest number on top
push the number to stack B
sort3 the remaining numbers in stack A
push the smallest number back to stack A
*/
void sort4(t_list **stack_a, t_list **stack_b)
{
    int i;

    i = 0;
    while (i < 4)
    {
        pb(stack_a, stack_b);
        i++;
    }
    simple_sort(stack_a, stack_b, 3);
    pa(stack_a, stack_b);
}

void sort5(t_list **stack_a, t_list **stack_b)
{
    int size;
    int i;

    size = 5;
    i = 0;
    while (i < size)
    {
        pb(stack_a, stack_b);
        i++;
    }
    simple_sort(stack_a, stack_b, 3);
    pa(stack_a, stack_b);
    ra(stack_a);
    pa(stack_a, stack_b);
}

void simple_sort(t_list **stack_a, t_list **stack_b, int size)
{
    if (is_sorted(stack_a))
        return;

    if (size == 2)
        sort2(stack_a);
    else if (size == 3)
        sort3(stack_a);
    else if (size == 4)
        sort4(stack_a, stack_b);
    else if (size == 5)
        sort5(stack_a, stack_b);
}
