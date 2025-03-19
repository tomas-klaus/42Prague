/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:08:43 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/19 19:31:27 by tklaus           ###   ########.fr       */
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
	/* if (cost_compute(moves[0], moves[2]) < cost)
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
	{
		cost = cost_compute(moves[1], moves[3]);
		case_which = 4;
	} */
	/* if ((ft_abs(moves[0] - moves[2]) <= cost) || (ft_abs(moves[1])
			- moves[3] <= cost))
		case_which = 5; */
	/* printf("which_caseMoves: ra[%d], rra[%d], rb[%d], rrb[%d]\n", moves[0],
		moves[1], moves[2], moves[3]);
	printf("final cost in which_case: %d\n", cost); */
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
	/* printf("stack_a: ");
	print_stack(stack_a);
	printf("stack_b: ");
	print_stack(stack_b); */
}
void	rotate_moves(t_list **stack_a, t_list **stack_b, int *moves, int *num)
{
	int	case_which;
	int	r_times;

	/* printf("Moves: 4:%d, 5:%d, 6:%d, 7:%d\n", moves[4], moves[5], moves[6],
		moves[7]); */
	case_which = which_case(stack_a, stack_b, moves, num);
	/* printf("exeMoves: ra[%d], rra[%d], rb[%d], rrb[%d], 4:%d, 5:%d, 6:%d,
		7:%d\n", moves[0], moves[1], moves[2], moves[3], moves[4], moves[5],
		moves[6], moves[7]); */
	// printf("which_case: %d\n", case_which);
	if (case_which == 1)
	{
		// printf("rotating both\n");
		r_times = ft_min(ft_abs(moves[4]), ft_abs(moves[6]));
		rotate_final(stack_a, stack_b, r_times);
	}
	else if (case_which == 4)
	{
		// printf("rotating both\n");
		r_times = ft_min(ft_abs(moves[5]), ft_abs(moves[7])) * -1;
		rotate_final(stack_a, stack_b, r_times);
	}
	/* printf("rotating separately to get %d(A) on top of %d(B)\n", num[0],
		num[1]); */
	rotate_distance(stack_a, num[0], 1);
	rotate_distance(stack_b, num[1], 0);
}

void	execute_moves(t_list **stack_a, t_list **stack_b, int *moves, int *num)
{
	/* printf("executing moves for numbers a[%d]b[%d]\n", num[0], num[1]);
	printf("ra[%d], rra[%d], rb[%d], rrb[%d]\n", moves[0], moves[1], moves[2],
		moves[3]); */
	/* while ((*stack_a)->content != num[0])
	{
		moves[0]++;
		(*stack_a) = (*stack_a)->next;
	}
	moves[1] = moves[0] - ft_lstsize(*stack_a);
	if ((num[0] < get_min(stack_b)) || (num[0] > get_max(stack_a)))
		num[1] = get_max(stack_b);
	else num[1] = get_next_lowest(stack_b, num[0]); */
	// b_cost(stack_b, num[0], moves);
	if (num[0] > get_max(stack_b) || num[0] < get_min(stack_b))
		num[1] = get_max(stack_b);
	else
		num[1] = get_next_lowest(stack_b, num[0]);
	rotate_moves(stack_a, stack_b, moves, num);
	pb(stack_a, stack_b);
}
