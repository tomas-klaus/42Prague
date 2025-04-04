/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:48:21 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/15 21:01:10 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    printf("rr\n");
}

void rra(t_list **stack)
{
    reverse_rotate(stack);
    printf("rra\n");
}

void rrb(t_list **stack)
{
    reverse_rotate(stack);
    printf("rrb\n");
}

void rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    printf("rrr\n");
}
