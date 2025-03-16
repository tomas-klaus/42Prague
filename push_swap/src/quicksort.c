/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:59:46 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/16 15:01:39 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void rotate_distance(t_list **stack, int min, int size)
{
    int dist;
    int i = 0;
    dist = get_distance(stack, min, size);

    while (i != dist)
    {
        if (dist > 0)
        {
            ra(stack);
            i++;
        }
        else if (dist < 0)
        {
            rra(stack);
            i--;
        }
    }
}

int push_smaller(t_list **stack_a, t_list **stack_b, int size, int pivot)
{
    t_list *first;
    int i;
    int j;

    i = 0;
    j = 0;

    while (i < size || j < size / 2)
    {
        first = *stack_a;
        if (first->content < pivot)
        {
            pb(stack_a, stack_b);
            j++;
        }
        /* add condition for rra using rotate_distance*/
        ra(stack_a);
        i++;
    }
    return (size - j);
}
/*
check if the number on top of stack_b == (stack_a->content) -1
if yes - push a
if no - rotate_distance and push a
*/
void push_back(t_list **stack_a, t_list **stack_b, int size)
{
    int next_num = (*stack_a)->content - 1;
    while (*stack_b)
    {
        if ((*stack_b)->content == next_num)
            pa(stack_a, stack_b);
        else
        {
            rotate_distance(stack_b, next_num, size);
            pa(stack_a, stack_b);
        }
        size--;
        next_num--;
    }
}

/*
choose a pivot (middle between the biggest and smallest number)
push smaller numbers to stack B
after splitting the stack, make a pivot again and repeat the process
until there are 3 or less numbers in stack A
sort the remaining numbers in stack A
push the numbers back to stack A in the correct order
*/
void quick_sort(t_list **stack_a, t_list **stack_b, int size)
{
    static int pivot = 0;

    int new_size;

    pivot = pivot + size / 2;

    if (size <= 3)
    {
        if (size == 3)
            sort3(stack_a);
        else
            sort2(stack_a);
        return;
    }
    new_size = push_smaller(stack_a, stack_b, size, pivot);
    quick_sort(stack_a, stack_b, new_size);
    push_back(stack_a, stack_b, ft_lstsize(*stack_b));
}
