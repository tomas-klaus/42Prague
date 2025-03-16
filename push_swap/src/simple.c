/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:55:58 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/16 11:59:18 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

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
find smallest number in stack A (0)
rotate the most efficient way to get the smallest number on top
push the number to stack B
sort3 the remaining numbers in stack A
push the smallest number back to stack A
*/
void sort4(t_list **stack_a, t_list **stack_b, int size)
{
    int dist;
    int i;
    int min;

    min = get_min(stack_a);
    i = 0;
    dist = get_distance(stack_a, min, size);

    while (i != dist)
    {
        if (dist > 0)
        {
            ra(stack_a);
            i++;
        }
        else if (dist < 0)
        {
            rra(stack_a);
            i--;
        }
    }
    pb(stack_a, stack_b);
    sort3(stack_a);
    pa(stack_a, stack_b);
}

void sort5(t_list **stack_a, t_list **stack_b, int size)
{
    int dist;
    int i;
    int min;

    min = get_min(stack_a);
    i = 0;
    dist = get_distance(stack_a, min, size);

    while (i != dist)
    {
        if (dist > 0)
        {
            ra(stack_a);
            i++;
        }
        else if (dist < 0)
        {
            rra(stack_a);
            i--;
        }
    }
    pb(stack_a, stack_b);
    sort4(stack_a, stack_b, 4);
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
        sort4(stack_a, stack_b, size);
    else if (size == 5)
        sort5(stack_a, stack_b, size);
}
