/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:08:43 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/19 21:24:32 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	which_case(t_list **stack_a, t_list **stack_b, int *moves, int *num)
{
	int	cost;
	int	case_which;

	case_which = 0;
	cost = INT_MAX;
	if ((*stack_a)->content == num[0] || (*stack_b)->content == num[1])
	{
		return (5);
	}
	if (moves[5] == INT_MAX && moves[7] == INT_MAX)
		case_which = 1;
	if (moves[5] == INT_MAX && moves[6] == INT_MAX)
		case_which = 2;
	if (moves[4] == INT_MAX && moves[7] == INT_MAX)
		case_which = 3;
	if (moves[4] == INT_MAX && moves[6] == INT_MAX)
		case_which = 4;
	return (case_which);
}

void	rotate_final(t_list **stack_a, t_list **stack_b, int r_times)
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

void	rotate_moves(t_list **stack_a, t_list **stack_b, int *moves, int *num)
{
	int	case_which;
	int	r_times;

	case_which = which_case(stack_a, stack_b, moves, num);
	if (case_which == 1)
	{
		r_times = ft_min(ft_abs(moves[4]), ft_abs(moves[6]));
		rotate_final(stack_a, stack_b, r_times);
	}
	else if (case_which == 4)
	{
		r_times = ft_min(ft_abs(moves[5]), ft_abs(moves[7])) * -1;
		rotate_final(stack_a, stack_b, r_times);
	}
	rotate_distance(stack_a, num[0], 1);
	rotate_distance(stack_b, num[1], 0);
}

void	execute_moves(t_list **stack_a, t_list **stack_b, int *moves, int *num)
{
	if (num[0] > get_max(stack_b) || num[0] < get_min(stack_b))
		num[1] = get_max(stack_b);
	else
		num[1] = get_next_lowest(stack_b, num[0]);
	rotate_moves(stack_a, stack_b, moves, num);
	pb(stack_a, stack_b);
}
