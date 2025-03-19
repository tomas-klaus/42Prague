/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:41:52 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/19 19:33:43 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

/*
- push two top numbers from stack_a (pb,pb)
- calculate the cost of moves
	- take each number from stack_a and calculate how many moves
	it would take for it to be on top (by ra or rra) and store the two values
	- decide where the number needs to go in stack_b (which number to get on top of b)
		- if its going to be the biggest or the lowest number in stack_b,
		i need to rotate stack_b till the current biggest is on top
		- if its going to be somewhere in the middle,
		i need to rotate stack_b till the second lowest from the num is on top
	- calculate how many moves it will take to get the right number on top of (by ra or rra) and store the two values
	- compare the costs
		- if both distances are positive or both negative -> ft_abs(dist_a
			- dist_b) + min(dist_a, dist_b)
		- if they have different znaminko -> ft_abs(dist_a) + ft_abs(dist_b)
	- get the cost for each number in stack_a and choose the cheapest
	- return the number i want to push
- execute the correct moves
	- take the number
	- decide where the number needs to go in stack_b (which number to get on top of b)
		- if its going to be the biggest or the lowest number in stack_b,
		i need to rotate stack_b till the current biggest is on top
		- if its going to be somewhere in the middle,
		i need to rotate stack_b till the second lowest from the num is on top
	- calculate how many moves it will take to get the right number on top of (by ra or rra) and store the two values
	- compare the costs
		- if both distances are positive or both negative -> ft_abs(dist_a
			- dist_b) + (max(ft_abs(dist_a), ft_abs(dist_b))min(ft_abs(dist_a),
				ft_abs(dist_b)))
		- if they have different znaminko -> ft_abs(dist_a) + ft_abs(dist_b)
	- take the lower cost
	- rotate
		- if both distances are positive -> r * min(ft_abs(dist_a),
			ft_abs(dist_b)), ra || rb * ft_abs(dist_a - dist_b)
		- if both negative -> rr * min(ft_abs(dist_a), ft_abs(dist_b)), rra
			|| rrb * ft_abs(dist_a - dist_b)
		- if they have different znaminko -> rotate distance(stack_a, num_a),
			rotate_distance(stack_b, num_b)
- push b and repeat till there are 3 nums in stack_a
- sort3 stack_a
- push back to stack_a till *stack_b != NULL
	- take the number from top of stack_b
	- find the next higher to it in stack_a
	- rotate_distance(stack_a, next_higher)
	- pa
- rotate_distance(stack_a, 0)
*/

void	push_back_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_b;
	int		first;
	int		num;

	/*  t_list *first_a;
		first_a = *stack_a; */
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
/* printf("compare_costsMoves: ra[%d], rra[%d], rb[%d], rrb[%d]\n",
		moves[0],
		moves[1], moves[2], moves[3]); */
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
	// printf(" %d\n", cost);
	return (cost);
}

void	b_cost(t_list **stack_b, int num_a, int *moves)
{
	/* printf("ra: %d, rra: %d, rb: %d, rrb: %d\n", moves[0], moves[1],
		moves[2], moves[3]);
	printf("cost for num: %d ->", num_a); */
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
	// printf("size_a in calculate_cost: %d\n", size_a);
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
			// printf("num: %d\n", num);
		}
		first_a = first_a->next;
		// print_stack(stack_a);
	}
	// printf("cost: %d\n", cost);
	
	return (num);
}

/*
moves[0] = ra
moves[1] = rra
moves[2] = rb
moves[3] = rrb
*/
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
		/* printf("stack_a: ");
		print_stack(stack_a);
		printf("stack_b: ");
		print_stack(stack_b); */
		num[0] = calculate_cost(stack_a, stack_b, full_size, moves);
		// printf("chose number %d\n", num[0]);
		execute_moves(stack_a, stack_b, moves, num);
		full_size--;
		/* printf("stack_a: ");
		print_stack(stack_a);
		printf("stack_b: ");
		print_stack(stack_b); */
	}
	sort3(stack_a);
	//printf("-------------pushing back----------\n");
	push_back_to_b(stack_a, stack_b);
	rotate_distance(stack_a, 0, 1);
}
