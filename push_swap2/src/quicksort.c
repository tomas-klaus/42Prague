/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:59:46 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/17 17:48:12 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

/*
stack_a is 1
stack_b is 0
*/
void rotate_distance(t_list **stack, int target, int size, int which_stack)
{
    int dist = get_distance(stack, target, size);

    // Optimize rotations
    while (dist != 0)
    {
        if (dist > 0)
        {
            if (which_stack)
                ra(stack);
            else
                rb(stack);
            dist--;
        }
        else if (dist < 0)
        {
            if (which_stack)
                rra(stack);
            else
                rrb(stack);
            dist++;
        }
    }
}
/*
locate the next closest smaller number
with a function that goes through the whole stack
and finds the smaller number than pivot closest to the top and to the bottom
and compares their distance from top
and returns the better one
*/
int closest_smaller(t_list **stack_a, int pivot, int size)
{
    /// printf("looking for closest smaller\n");
    t_list *first;
    int top;
    int bot;
    int dist_top;
    int dist_bot;

    first = *stack_a;
    top = 0;

    // printf("\npivot: %d\nsize: %d\n", pivot, size);

    bot = closest_bot(first, pivot);

    dist_top = closest_top(first, pivot, &top);
    dist_bot = get_distance(stack_a, bot, size);

    // printf("top: %d\nbot: %d\ndist_top: %d\ndist_bot: %d\n\n", top, bot, dist_top, dist_bot);

    if (ft_abs(dist_top) > ft_abs(dist_bot))
        return bot;
    else
        return top;
}

int push_smaller(t_list **stack_a, t_list **stack_b, int size, int pivot)
{
    t_list *first;
    int i;
    int j;
    int closest;

    i = 0;
    j = 0;
    closest = 0;

    // printf("pivot: %d\n", pivot);

    while (i < size && j < size / 2 && (size - j) > 3)
    {
        first = *stack_a;
        if (first->content < pivot)
        {
            pb(stack_a, stack_b);
            j++;
        }
        else
        {
            closest = closest_smaller(stack_a, pivot, size - j);
            rotate_distance(stack_a, closest, size - j, 1);
        }
        i++;
        /*  printf("j: %d\n", j);
         printf("curr size: %d\n", size - j); */
    }
    return (size - j);
}
/*
check if the number on top of stack_b == (stack_a->content) -1
if yes - push a
if no - rotate_distance and push a
*/

/* void push_back(t_list **stack_a, t_list **stack_b, int size)
{
    printf("pushing back\n");
    int next_num = (*stack_a)->content - 1;

    while (*stack_b && next_num >= 0)
    {
        if ((*stack_b)->content == next_num)
            pa(stack_a, stack_b);
        else
        {
            rotate_distance(stack_b, next_num, size, 0);
            pa(stack_a, stack_b);
        }
        size--;
        next_num--;
    }
} */

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
        printf("sorting small\n");
        if (size == 3)
            sort3(stack_a);
        else
            sort2(stack_a);
        return;
    }
    new_size = push_smaller(stack_a, stack_b, size, pivot);
    quick_sort(stack_a, stack_b, new_size);
    size = ft_lstsize(*stack_a);
    push_back(stack_a, stack_b, size, ft_lstsize(*stack_b));
}
