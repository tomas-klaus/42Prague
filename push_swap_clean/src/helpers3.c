/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:11 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/19 21:26:15 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	cost_compute(int i, int j)
{
	if ((i >= 0 && j >= 0) || (i < 0 && j < 0))
		return (ft_abs(i - j) + ft_min(ft_abs(i), ft_abs(j)));
	else
		return (ft_abs(i) + ft_abs(j));
}

void	rotate_distance(t_list **stack, int target, int which_stack)
{
	int	size;
	int	dist;

	size = ft_lstsize(*stack);
	dist = get_distance(stack, target, size);
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

void	reset_moves(int *moves)
{
	moves[4] = INT_MAX;
	moves[5] = INT_MAX;
	moves[6] = INT_MAX;
	moves[7] = INT_MAX;
}

void	get_best_moves(int cost, int *moves)
{
	reset_moves(moves);
	if (cost_compute(moves[0], moves[2]) == cost)
	{
		moves[4] = moves[0];
		moves[6] = moves[2];
		return ;
	}
	if (cost_compute(moves[0], moves[3]) == cost)
	{
		moves[4] = moves[0];
		moves[7] = moves[3];
		return ;
	}
	if (cost_compute(moves[1], moves[2]) == cost)
	{
		moves[5] = moves[5];
		moves[6] = moves[2];
		return ;
	}
	if (cost_compute(moves[1], moves[3]) == cost)
	{
		moves[5] = moves[1];
		moves[7] = moves[3];
		return ;
	}
}
