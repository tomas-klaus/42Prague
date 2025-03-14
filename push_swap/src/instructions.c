/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:37:29 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/14 19:17:25 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
swap
the first node is t_list stack_a
the second node is stack_a->next
make int tmp_value and store first->value
first->value = second->value
second->value = tmp_value
	sa
	sb
	ss

push
basically just make a new node in stack_b
and assign the value of the stack_a first node and delete it (and free?)
make the first->next the new first (first = first->next)
	pa
	pb

rotate
store the first->value int temp
make the first->next the new first (first = first->next)
delete the first and free?
add a new node to the back of the list and paste the value from temp (ft_lst_addback)
	ra
	rb
	rr
reverse rotate
	rra
	rrb
	rrr
*/

#include "../include/header.h"
