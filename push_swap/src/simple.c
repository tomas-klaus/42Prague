/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:55:58 by tklaus            #+#    #+#             */
/*   Updated: 2025/03/14 18:36:08 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void simple_sort(t_list **stack_a, t_list **stack_b, int size)
{
    if (is_sorted(stack_a))
		return ;
    
    if (size == 2)
        sort2(stack_a);
    else if (size == 3)
        sort3(stack_a);
    else if (size == 4)
        sort4(stack_a, stack_b);
    else if (size == 5)
        sort5(stack_a, stack_b);
}
