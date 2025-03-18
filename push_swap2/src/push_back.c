/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:54:04 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/18 00:56:10 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int is_in_stack(t_list **stack, int num)
{
    t_list *current;

    current = *stack;
    while (current)
    {
        if (current->content == num)
            return 1;
        current = current->next;
    }
    return 0;
}

int compare_distance(t_list **stack_a, t_list **stack, int num, int size_a, int size_b, int orig_dist, int *minus)
{
    int dist_minus;
    int dist_plus;
    if (size_a > size_b)
    {
        dist_minus = size_a * 2;
        dist_plus = size_a * 2;
    }
    else
    {
        dist_minus = size_b * 2;
        dist_plus = size_b * 2;
    }
    int dist = 0;

    /* check if num-1 or num +1 already are in stack. if yes, return orig dest*/

    if (num - 1 >= 0 && !(is_in_stack(stack_a, num - 1)))
        dist_minus = get_distance(stack, num - 1, size_b);
    if (num + 1 <= (ft_lstlast(*stack)->content) && !(is_in_stack(stack_a, num + 1)))
        dist_plus = get_distance(stack, num + 1, size_b);
    /* printf("comparing nums: %d,%d dist to %d is %d\n", num - 1, num + 1, num, (ft_abs(dist_minus) < ft_abs(dist_plus) ? ft_abs(dist_minus) : ft_abs(dist_plus)));
    printf("dist_minus: %d\n", ft_abs(dist_minus));
    printf("dist_plus: %d\n", ft_abs(dist_plus));
    printf("orig_dist: %d\n", ft_abs(orig_dist)); */

    if (ft_abs(dist_minus) > ft_abs(dist_plus))
    {
        dist = dist_plus;
        *minus = 0;
    }
    else
    {
        dist = dist_minus;
        *minus = 1;
    }
    /* if (*minus)
        printf("chose +1\n");
    else
        printf("chose -1\n"); */
    if (ft_abs(orig_dist) > ft_abs(dist))
        return dist;
    else
        return orig_dist;
}

int iterate_stack(t_list **stack_a, t_list **stack_b, int *num, int size_a, int size_b, int *minus)
{
    t_list *first;
    int dist;
    int min_dist;
    int i;
    int j;
    int final_minus;

    j = 0;
    final_minus = 0;
    if (size_a > size_b)
    {
        min_dist = size_a * 2;
        dist = size_a * 2;
    }
    else
    {
        min_dist = size_b * 2;
        dist = size_b * 2;
    }

    i = 0;
    first = *stack_a;
    while (first && i < size_a)
    {
        if (i > size_a / 2)
            j = (i - size_a);
        j = i;
        dist = compare_distance(stack_a, stack_b, first->content, size_a, size_b, dist, minus);

        /* printf("evaluating num: %d, dist to %d is %d\n", first->content, (*minus ? first->content - 1 : first->content + 1), ft_abs(dist));
        printf("cost of %d: %d\n", first->content, ft_abs(dist) + ft_abs(j)); */
        printf("moves on b: %d, moves on a %d\n", ft_abs(dist), ft_abs(j));
        if (ft_abs(min_dist) > ft_abs(dist) + ft_abs(j))
        {
            final_minus = *minus;
            min_dist = ft_abs(dist) + ft_abs(j);
            *num = first->content;
            // printf("new best number: %d, dist to num: %d\n", *num, ft_abs(min_dist));
        }
        // printf("min_dist: %d\n", min_dist);
        first = first->next;
        i++;
    }
    /* printf("B rotations needed: %d\n", min_dist);
    printf("A rotations needed: %d\n", j);
    printf("final_minus: %d\n", final_minus);  */
    return final_minus;
}
/*
select a number in between 0 and the lowest number in stack a (init_high)
find that number in stack b and push it to stack a
then try to find either a one smaller than that or one bigger than that in stack b
and compare the moves it would take to get it on top of b and push to a
iterate through all the numbers that are lower than init_high
and compare the moves it would take to get a number one higher or one lower above or below them
and chose the most efficient one
 */
void push_back(t_list **stack_a, t_list **stack_b, int size_a, int size_b)
{
    // int init_size;
    /*  int init_high;
     init_high = size_b; */
    // init_size = size_a;

    int num;
    int minus = 0;
    int final_minus = 0;
    num = size_b / 2;
    /* print_stack(stack_a);
    print_stack(stack_b); */

    rotate_distance(stack_b, num, size_b, 0);
    pa(stack_a, stack_b);
    size_a++;
    size_b--;

    while (*stack_b)
    {
        print_stack(stack_a);
        print_stack(stack_b);
        final_minus = iterate_stack(stack_a, stack_b, &num, size_a, size_b, &minus);
        // printf("num: %d\n", num);
        if (final_minus)
        {
            // printf("num-1: %d\n", num - 1);
            rotate_distance(stack_b, num - 1, size_b, 0);
        }
        else
        {
            // printf("num+1: %d\n", num + 1);
            rotate_distance(stack_b, num + 1, size_b, 0);
        }
        /* if condition for if im pushing num+1 or num-1 */
        rotate_distance(stack_a, num, size_a, 1);
        if (!final_minus)
            ra(stack_a);
        pa(stack_a, stack_b);
        size_b--;
        size_a++;
    }
    rotate_distance(stack_a, 0, size_a, 1);
}
