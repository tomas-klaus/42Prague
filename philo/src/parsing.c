/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:03:21 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/05/15 10:57:39 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    unsigned long long int nb;
    int i;

    i = 0;
    nb = 0;
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    if (nb > INT_MAX)
        return (-1);
    return ((int)nb);
}
int parse_args(int argc, char **argv)
{
    int i = 1;
    int j;
    long num;

    while (i < argc)
    {
        j = 0;
        if (argv[i][j] == '\0' || (argv[i][j] == '-'))
            return (msg("Error: Invalid argument\n", 0));
        while (argv[i][j] != '\0')
        {
            if (!ft_isdigit(argv[i][j]))
                return (msg("Error: Not a digit\n", 0));
            j++;
        }
        num = ft_atoi(argv[i]);
        if (num <= 0 && i != 5)
            return (msg("Error: Argument has to be greater than 0\n", 0));
        i++;
    }
    return (1);
}
