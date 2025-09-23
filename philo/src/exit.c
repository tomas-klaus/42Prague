/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:05:25 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/23 10:15:04 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	unlock_forks(t_table *table, int id)
{
	int	first;
	int	second;

	assign_forks(&first, &second, table, id);
	table->fork[second] = -1;
	pthread_mutex_unlock(&table->fork_mutex[second]);
	table->fork[first] = -1;
	pthread_mutex_unlock(&table->fork_mutex[first]);
}

int	msg(char *str, int exit_no)
{
	printf("%s", str);
	return (exit_no);
}

void	dest_mutex(t_table *table)
{
	int	i;

	i = 0;
	if (table->philos)
	{
		while (i < table->philo_count)
		{
			pthread_mutex_destroy(&table->philos[i].last_meal_mutex);
			pthread_mutex_destroy(&table->philos[i].times_ate_mutex);
			i++;
		}
	}
}

/* Calculate the time remaining until the philosopher
would die and sleep for that amount of time */
int	think_routine(t_table *table, int id)
{
	time_t	now;
	time_t	last_meal;
	time_t	time_since_last_meal;
	time_t	time_remaining;

	pthread_mutex_lock(&table->write_lock);
	printf("%ld %d is thinking\n", get_timestamp(table), id + 1);
	pthread_mutex_unlock(&table->write_lock);
	now = get_time();
	pthread_mutex_lock(&table->philos[id].last_meal_mutex);
	last_meal = table->philos[id].last_meal;
	pthread_mutex_unlock(&table->philos[id].last_meal_mutex);
	time_since_last_meal = now - last_meal;
	time_remaining = table->die_time - time_since_last_meal;
	if (time_remaining > 0)
	{
		if (philo_sleep(table, (time_remaining - 10), id))
			return (1);
	}
	return (0);
}

void	cleanup(t_table *table)
{
	int	i;

	i = 0;
	if (table->fork_mutex)
	{
		while (i < table->philo_count)
		{
			pthread_mutex_destroy(&table->fork_mutex[i]);
			i++;
		}
		free(table->fork_mutex);
	}
	dest_mutex(table);
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->stop_flag_mutex);
	if (table->fork)
		free(table->fork);
	if (table->philos)
		free(table->philos);
}
