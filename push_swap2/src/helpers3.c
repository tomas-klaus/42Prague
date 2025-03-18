/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:11 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/18 17:36:23 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int ft_min(int a, int b)
{
    return (a < b) ? a : b;
}

int cost_compute(int i, int j)
{
    if ((i >= 0 && j >= 0) || (i < 0 && j < 0))
        return ft_abs(i - j) + ft_min(ft_abs(i), ft_abs(j));
    else
        return ft_abs(i) + ft_abs(j);
}
void rotate_distance(t_list **stack, int target, int which_stack)
{
    int size;
    size = ft_lstsize(*stack);
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