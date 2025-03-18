/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:09:41 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/18 16:55:34 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int get_min(t_list **stack)
{
    t_list *first;
    int min;

    first = *stack;
    min = first->content;
    while (first->next)
    {
        if (min > first->next->content)
            min = first->next->content;
        first = first->next;
    }
    return (min);
}



/*
get the distance of the requested node from the top
if its smaller or equal than size/2 -> return the distance
else if its bigger than size/2 -> return (size-distance)*-1
*/

int get_distance(t_list **stack, int value, int size)
{
    t_list *first;
    int dist;

    dist = 0;
    first = *stack;

    while (first && (first->content != value))
    {
        first = first->next;
        dist++;
    }
    if (!first)
        return size;
    if (dist > size / 2)
        return (dist - size);
    return (dist);
}

int ft_sort(int *sorted_arr, int count)
{
    int temp;
    int i;
    int j;

    i = 0;
    while (i < count - 1)
    {
        j = 0;
        while (j < count - i - 1)
        {
            if (sorted_arr[j] > sorted_arr[j + 1])
            {
                temp = sorted_arr[j];
                sorted_arr[j] = sorted_arr[j + 1];
                sorted_arr[j + 1] = temp;
            }
            else if (sorted_arr[j] == sorted_arr[j + 1])
                return (1);
            j++;
        }
        i++;
    }
    i = 0;
    return (0);
}

int count_arrays(char **arr)
{
    int count;

    count = 0;
    while (arr[count] != NULL)
    {
        count++;
    }
    return (count);
}

int check_overflow(char *str)
{
    int i;
    int minus;
    long long result;

    if (!str)
        return (0);
    result = 0;
    i = 0;
    minus = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            minus++;
        i++;
    }
    while ((str[i] >= 48 && str[i] <= 57))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (minus)
        result *= -1;
    if (result > 2147483647 || result < -2147483648)
        return (1);
    return (0);
}
