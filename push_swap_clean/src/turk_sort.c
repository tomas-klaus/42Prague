/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:41:52 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/19 21:18:59 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	push_back_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_b;
	int		first;
	int		num;

	first_b = *stack_b;
	while (*stack_b)
	{
		first_b = *stack_b;
		first = first_b->content;
		num = get_next_higher(stack_a, first);
		rotate_distance(stack_a, num, 1);
		pa(stack_a, stack_b);
	}
}

int	compare_costs(int *moves, int size_a, int i)
{
	int	cost;

	moves[1] = (size_a - i) * -1;
	cost = size_a;
	if (cost_compute(i, moves[2]) < cost)
		cost = cost_compute(i, moves[2]);
	if (cost_compute(i, moves[3]) < cost)
		cost = cost_compute(i, moves[3]);
	if (cost_compute(moves[1], moves[2]) < cost)
		cost = cost_compute(moves[1], moves[2]);
	if (cost_compute(moves[1], moves[3]) < cost)
		cost = cost_compute(moves[1], moves[3]);
	return (cost);
}

void	b_cost(t_list **stack_b, int num_a, int *moves)
{
	if ((num_a < get_min(stack_b)) || (num_a > get_max(stack_b)))
	{
		get_both_distances(stack_b, get_max(stack_b), &moves[2], &moves[3]);
	}
	else
		get_both_distances(stack_b, get_next_lowest(stack_b, num_a), &moves[2],
			&moves[3]);
}

int	calculate_cost(t_list **stack_a, t_list **stack_b, int size_a, int *moves)
{
	int		num;
	int		cost;
	t_list	*first_a;
	int		i;

	i = -1;
	first_a = *stack_a;
	cost = size_a;
	num = 0;
	while (first_a)
	{
		i++;
		b_cost(stack_b, first_a->content, moves);
		if (compare_costs(moves, size_a, i) < cost)
		{
			cost = compare_costs(moves, size_a, i);
			num = first_a->content;
			moves[0] = i;
			get_best_moves(cost, moves);
		}
		first_a = first_a->next;
	}
	return (num);
}

void	turk_sort(t_list **stack_a, t_list **stack_b, int full_size)
{
	int	moves[8];
	int	num[2];

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	full_size = full_size - 2;
	moves[0] = 0;
	moves[1] = 0;
	moves[2] = 0;
	moves[3] = 0;
	moves[4] = INT_MAX;
	moves[5] = INT_MAX;
	moves[6] = INT_MAX;
	moves[7] = INT_MAX;
	num[0] = 0;
	num[1] = 0;
	while (full_size > 3)
	{
		num[0] = calculate_cost(stack_a, stack_b, full_size, moves);
		execute_moves(stack_a, stack_b, moves, num);
		full_size--;
	}
	sort3(stack_a);
	push_back_to_b(stack_a, stack_b);
	rotate_distance(stack_a, 0, 1);
}
