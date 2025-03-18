/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:20:51 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/16 22:58:38 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int closest_top(t_list *stack, int pivot, int *top)
{
    int i;
    i = 0;

    if (stack == NULL)
        return 0;
    
    while (stack)
    {
        if (stack->content < pivot)
        {
            *top = stack->content;
            return (i);
        }
        stack = stack->next;
        i++;
    }
    return 0;
}

int closest_bot(t_list *stack, int pivot)
{
    int bot = 0;

    if (stack == NULL)
        return bot;

    while (stack)
    {
        if (stack->content < pivot)
        {
            
            bot = stack->content;
        }
        stack = stack->next;
    }
    return bot;
}

int ft_abs(int num)
{
    if (num < 0)
        return -num;
    return num;
}
