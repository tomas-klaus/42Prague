/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:43 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/19 21:28:09 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

int		*parse_input(int argc, char **argv, int *size);

/* helpers */
int		get_distance(t_list **stack, int value, int size);
int		ft_sort(int *sorted_arr, int count);
int		count_arrays(char **arr);
int		check_overflow(char *str);
int		get_min(t_list **stack);

/* helpers2 */
int		ft_abs(int num);
void	get_both_distances(t_list **stack, int value, int *r_dist,
			int *rr_dist);
int		get_max(t_list **stack);
int		get_next_lowest(t_list **stack, int num);
int		get_next_higher(t_list **stack, int num);

/* helpers3 */
int		ft_min(int a, int b);
int		cost_compute(int i, int j);
void	rotate_distance(t_list **stack, int target, int which_stack);
void	get_best_moves(int cost, int *moves);

/* stack */
int		init_stack(t_list **stack_a, t_list **stack_b, int *arr, int size);
void	print_stack(t_list **stack);
void	free_stack(t_list **stack);
int		is_sorted(t_list **stack);

/* instructions */
void	swap(t_list *stack);
void	pa(t_list **stack_to, t_list **stack_from);
void	pb(t_list **stack_from, t_list **stack_to);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/* simple */
void	sort2(t_list **stack);
void	sort3(t_list **stack);
void	simple_sort(t_list **stack_a, t_list **stack_b, int size);

/* execute moves */
void	execute_moves(t_list **stack_a, t_list **stack_b, int *moves, int *num);

void	turk_sort(t_list **stack_a, t_list **stack_b, int full_size);
void	b_cost(t_list **stack_b, int num_a, int *moves);

int		free_2d_array(char **array);
void	free_int_2d_array(int **array, int size);

#endif