/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:43 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/14 17:45:09 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*value;
	struct s_list	*next;
}					t_list;

int					ft_sort(int *sorted_arr, int count);
int					*parse_input(int argc, char **argv, int *size);
int					count_arrays(char **arr);
int					check_overflow(char *str);
int					init_stack(t_list **stack_a, t_list **stack_b, int *arr,
						int size);

#endif