/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:02:26 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/15 12:45:19 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void fork_routine(t_table *table, int id)
{
    pthread_mutex_lock(&table->fork_mutex[id]);
    pthread_mutex_lock(&table->write_lock);
    printf("%ld %d has taken a fork\n", get_timestamp(table), id + 1);
    pthread_mutex_unlock(&table->write_lock);
    if (id == table->philo_count - 1)
        pthread_mutex_lock(&table->fork_mutex[0]);
    else
        pthread_mutex_lock(&table->fork_mutex[id + 1]);
    pthread_mutex_lock(&table->write_lock);
    printf("%ld %d has taken a fork\n", get_timestamp(table), id + 1);
    pthread_mutex_unlock(&table->write_lock);
}

int eat_routine(t_table *table, int id)
{
    int err;
    err = 0;
    pthread_mutex_lock(&table->write_lock);
    printf("%ld %d is eating\n", get_timestamp(table), id + 1);
    pthread_mutex_unlock(&table->write_lock);

    pthread_mutex_lock(&table->philos[id].last_meal_mutex);
    table->philos[id].last_meal = get_time();
    pthread_mutex_unlock(&table->philos[id].last_meal_mutex);

    pthread_mutex_lock(&table->philos[id].times_ate_mutex);
    table->philos[id].times_ate++;
    pthread_mutex_unlock(&table->philos[id].times_ate_mutex);

    if (philo_sleep(*table, table->eat_time, id))
        err = 1;

    pthread_mutex_unlock(&table->fork_mutex[id]);
    if (id == table->philo_count - 1)
        pthread_mutex_unlock(&table->fork_mutex[0]);
    else
        pthread_mutex_unlock(&table->fork_mutex[id + 1]);
    return err;
}

int sleep_routine(t_table *table, int id)
{
    pthread_mutex_lock(&table->write_lock);
    printf("%ld %d is sleeping\n", get_timestamp(table), id + 1);
    pthread_mutex_unlock(&table->write_lock);
    if (philo_sleep(*table, table->sleep_time, id))
        return 1;
    return 0;
}

void *philo_loop(void *arg)
{
    thread_data_t data = *(thread_data_t *)arg;
    t_table *table = data.table;
    int id = data.id;

    
    if ((id + 1) % 2 == 0)
        usleep(50);
    while (1)
    {
        // printf("stop_flag = %d\n", table->stop_flag);
        if (philo_sleep(*table, -1, id))
            break;
        fork_routine(table, id);
        if (philo_sleep(*table, -1, id))
            break;
        if (eat_routine(table, id))
            break;
        if (philo_sleep(*table, -1, id))
            break;
        if (sleep_routine(table, id))
            break;
        if (philo_sleep(*table, -1, id))
            break;
        pthread_mutex_lock(&table->write_lock);
        printf("%ld %d is thinking\n", get_timestamp(table), id + 1);
        pthread_mutex_unlock(&table->write_lock);
    }
    return NULL;
}