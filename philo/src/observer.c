/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:01:38 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/15 19:58:25 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	check_times_ate(t_table *table)
{
	int	j;

	j = 0;
	if (table->must_eat_count > 0)
	{
		while (j < table->philo_count)
		{
			pthread_mutex_lock(&table->philos[j].times_ate_mutex);
			if (table->philos[j].times_ate < table->must_eat_count)
			{
				pthread_mutex_unlock(&table->philos[j].times_ate_mutex);
				break ;
			}
			pthread_mutex_unlock(&table->philos[j].times_ate_mutex);
			j++;
		}
		if (j == table->philo_count)
		{
			// only for testing
			pthread_mutex_lock(&table->write_lock);
			printf("%ld All philosophers have eaten at least %d times\n",
				get_timestamp(table), table->must_eat_count);
			pthread_mutex_unlock(&table->write_lock);
			return (-1);
		}
	}
	return (0);
}

int	check_death(int i, t_table *table)
{
	time_t	die_time;
	time_t	last_meal;

	die_time = table->die_time;
	pthread_mutex_lock(&table->philos[i].last_meal_mutex);
	last_meal = table->philos[i].last_meal;
	pthread_mutex_unlock(&table->philos[i].last_meal_mutex);
	if ((get_time() - last_meal) > die_time)
		return (i);
	return (check_times_ate(table));
}

void	*obs_loop(void *arg)
{
	t_table	*table;
	int		i;
	int		err;

	table = (t_table *)arg;
	err = 0;
	while (1)
	{
		i = 0;
		while (i < table->philo_count)
		{
			err = check_death(i, table);
			if (err)
			{
				pthread_mutex_lock(&table->stop_flag_mutex);
				table->stop_flag = err;
				pthread_mutex_unlock(&table->stop_flag_mutex);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (0);
}
