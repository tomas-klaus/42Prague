/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:08:43 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/19 14:45:03 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int which_case(int *moves)
{
    int cost;
    int case_which;

    case_which = 0;
    cost = INT_MAX;
    if (cost_compute(moves[0], moves[2]) < cost)
    {
        cost = cost_compute(moves[0], moves[2]);
        case_which = 1;
    }
    if (cost_compute(moves[0], moves[3]) < cost)
    {
        cost = cost_compute(moves[0], moves[3]);
        case_which = 2;
    }
    if (cost_compute(moves[1], moves[2]) < cost)
    {
        cost = cost_compute(moves[1], moves[2]);
        case_which = 3;
    }
    if (cost_compute(moves[1], moves[3]) < cost)
        case_which = 4;
    return case_which;
}

void rotate_final(t_list **stack_a, t_list **stack_b, int r_times)
{
    while (r_times > 0)
    {
        rr(stack_a, stack_b);
        r_times--;
    }
    while (r_times < 0)
    {
        rrr(stack_a, stack_b);
        r_times++;
    }
}
void rotate_moves(t_list **stack_a, t_list **stack_b, int *moves, int *num)
{
    int case_which;
    int r_times;
    case_which = which_case(moves);

    if (case_which == 1)
    {
        //printf("rotating both\n");
        r_times = ft_min(ft_abs(moves[0]), ft_abs(moves[2]));
        rotate_final(stack_a, stack_b, r_times);
        
    }
    else if (case_which == 4)
    {
        //printf("rotating both\n");
        r_times = ft_min(ft_abs(moves[1]), ft_abs(moves[3])) * -1;
        rotate_final(stack_a, stack_b, r_times);
        

    }
    //printf("rotating separately\n");
    rotate_distance(stack_a, num[0], 1);
    rotate_distance(stack_b, num[1], 0);
    
}

void execute_moves(t_list **stack_a, t_list **stack_b, int *moves, int *num)
{
    /* printf("executing moves for numbers a[%d]b[%d]\n", num[0], num[1]);
    printf("ra[%d], rra[%d], rb[%d], rrb[%d]\n", moves[0], moves[1], moves[2], moves[3]); */

    /* while ((*stack_a)->content != num[0])
    {
        moves[0]++;
        (*stack_a) = (*stack_a)->next;
    }
    moves[1] = moves[0] - ft_lstsize(*stack_a);
    if ((num[0] < get_min(stack_b)) || (num[0] > get_max(stack_a)))
        num[1] = get_max(stack_b);
    else num[1] = get_next_lowest(stack_b, num[0]); */

    //b_cost(stack_b, num[0], moves);
    
    rotate_moves(stack_a, stack_b, moves, num);
   
    pb(stack_a, stack_b);
}
