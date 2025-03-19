/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:20:51 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/19 14:23:57 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int ft_abs(int num)
{
    if (num < 0)
        return -num;
    return num;
}

void get_both_distances(t_list **stack, int value, int *r_dist, int *rr_dist)
{
    t_list *first;
    first = *stack;
    int dist;
    int size;

    size = ft_lstsize(first);
    dist = 0;
    first = *stack;

    while (first && (first->content != value))
    {
        first = first->next;
        dist++;
    }
    if (!first)
    {
        *r_dist = size;
        *rr_dist = size;
    }
    *r_dist = dist;
    *rr_dist = dist - size;
}

int get_max(t_list **stack)
{
    int highest;
    t_list *current;

    if (!*stack)
        return (0); // or some error value

    current = *stack;
    highest = current->content;
    while (current)
    {
        if (current->content > highest)
            highest = current->content;
        current = current->next;
    }
    return (highest);
}

int get_next_lowest(t_list **stack, int num)
{
    int next_lowest;
    t_list *current;

    current = *stack;
    next_lowest = 0;

    while (current)
    {
        if (current->content < num && current->content > next_lowest)
        {
            next_lowest = current->content;
        }
        current = current->next;
    }
    //printf("Next_lowest: %d\n",next_lowest);
    return next_lowest;
}

int get_next_higher(t_list **stack, int num)
{
    int next_higher;
    int max;

    max = get_max(stack);
    next_higher = max;
    if (num > max)
        return (get_min(stack));

    t_list *current;

    current = *stack;
    while (current)
    {
        if (current->content > num && current->content < next_higher)
        {

            next_higher = current->content;
        }

        current = current->next;
    }

    return next_higher;
}