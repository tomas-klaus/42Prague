/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:28:07 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/06 14:11:31 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_table fill_params(char **argv){
    int error = 0;
    t_table table;
    table.stop_flag = 0;
    table.philo_count = ft_safe_atoi(argv[1], &error);
    table.die_time = (time_t)ft_safe_atoi(argv[2], &error);
    table.eat_time = (time_t)ft_safe_atoi(argv[3], &error);
    table.sleep_time = (time_t)ft_safe_atoi(argv[4], &error);
    if (argv[5])
        table.must_eat_count = ft_safe_atoi(argv[5], &error);
    if(error)
        return ((table.philo_count = 0), table);
    return table;
}

t_table init_structs(int argc, char **argv)
{
    t_table table;

    int i = 1;
    table = fill_params(argv);
    if (table.philo_count == 0)
        return (table);
    table.fork_mutex = malloc(sizeof(pthread_mutex_t) * argc);
    table.philos = malloc(sizeof(t_philo) * argc);
    while (i<argc){
        pthread_mutex_init(&table.fork_mutex[i], NULL);
        table.philos[i].id = i;
        table.philos[i].times_ate = 0;
        i++;
    }
    return table;
}
