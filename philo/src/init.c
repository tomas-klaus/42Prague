/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:28:07 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/15 19:55:42 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	assign_forks(int *first, int *second, t_table *table, int id)
{
	int	left;
	int	right;

	left = id;
	right = (id + 1) % table->philo_count;
	if (left < right)
	{
		*first = left;
		*second = right;
	}
	else
	{
		*first = right;
		*second = left;
	}
}

t_table	fill_params(char **argv)
{
	int		error;
	t_table	table;

	error = 0;
	table.stop_flag = 0;
	table.philo_count = ft_safe_atoi(argv[1], &error);
	table.die_time = (time_t)ft_safe_atoi(argv[2], &error);
	table.eat_time = (time_t)ft_safe_atoi(argv[3], &error);
	table.sleep_time = (time_t)ft_safe_atoi(argv[4], &error);
	if (argv[5])
		table.must_eat_count = ft_safe_atoi(argv[5], &error);
	else
		table.must_eat_count = -1;
	if (error)
		return ((table.philo_count = 0), table);
	return (table);
}

t_table	init_structs(char **argv)
{
	t_table	table;
	int		i;

	i = 0;
	table = fill_params(argv);
	if (table.philo_count == 0)
		return (table);
	table.fork_mutex = malloc(sizeof(pthread_mutex_t) * table.philo_count);
	table.philos = malloc(sizeof(t_philo) * table.philo_count);
	table.fork = malloc(sizeof(int) * table.philo_count);
	while (i < table.philo_count)
	{
		table.fork[i] = -1;
		pthread_mutex_init(&table.fork_mutex[i], NULL);
		table.philos[i].id = i;
		table.philos[i].times_ate = 0;
		i++;
	}
	return (table);
}
