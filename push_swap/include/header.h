/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:43 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/15 20:24:45 by tomasklaus       ###   ########.fr       */
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

int ft_sort(int *sorted_arr, int count);
int *parse_input(int argc, char **argv, int *size);
int count_arrays(char **arr);
int check_overflow(char *str);
int init_stack(t_list **stack_a, t_list **stack_b, int *arr,
			   int size);
void swap(t_list *stack);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);
void rotate(t_list **stack);
void reverse_rotate(t_list **stack);

void print_stack(t_list **stack);
void free_stack(t_list **stack);
int is_sorted(t_list **stack);
void simple_sort(t_list **stack_a, t_list **stack_b, int size);

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