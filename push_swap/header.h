/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:22:43 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/02/28 23:02:09 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>



int ft_sort(int *sorted_arr, int count);
int	*parse_input(int argc, char **argv);
int count_arrays(char **arr);
int check_overflow(char *str);


#endif