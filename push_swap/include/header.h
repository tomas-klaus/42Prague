/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:43 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/16 11:48:47 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

/* typedef struct s_list
{
	void *value;
	struct s_list *next;
} t_list; */

int *parse_input(int argc, char **argv, int *size);

void simple_sort(t_list **stack_a, t_list **stack_b, int size);

/* helpers */
int get_distance(t_list **stack, int value, int size);
int ft_sort(int *sorted_arr, int count);
int count_arrays(char **arr);
int check_overflow(char *str);
int get_min(t_list **stack);

/* stack */
int init_stack(t_list **stack_a, t_list **stack_b, int *arr,
			   int size);
void print_stack(t_list **stack);
void free_stack(t_list **stack);
int is_sorted(t_list **stack);

/* instructions */
void swap(t_list *stack);
void pa(t_list **stack_to, t_list **stack_from);
void pb(t_list **stack_from, t_list **stack_to);
void rotate(t_list **stack);
void reverse_rotate(t_list **stack);

void sa(t_list **stack_a);
void sb(t_list **stack_b);
void ss(t_list *stack_a, t_list *stack_b);
void ra(t_list **stack_a);
void rb(t_list **stack_b);
void rr(t_list **stack_a, t_list **stack_b);
void rra(t_list **stack_a);
void rrb(t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);

#endif