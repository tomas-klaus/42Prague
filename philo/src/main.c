/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:23:40 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/08/20 16:42:31 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 take args
    number_of_philosophers
    time_to_die, time_to_eat
    time_to_sleep
    [number_of_times_each_philosopher_must_eat]
parse args so theres 4-5 of them and theyre numbers and bigger than 0 (except the last one which can be 0)

initialize all the necessary structures
    general table
        all the args
        observer thread
        global mutexes
            write mutex
            fork mutexes
        start time
    structure for each philosophers
        id
        forks
        times ate
        meal time mutex
        last meal time
        thread
        table
init philos, assign forks, init mutexes
start simulation
    get time
    create threads
        run philosophers routines

stop simulation
    join threads
    destroy mutexes
    free table


-----------------------------------------------------------------------
philo routines

exit functions

output functions

time functions

 */

#include "../include/header.h"

time_t get_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

time_t get_timestamp(t_table *table)
{
    time_t timestamp = get_time() - table->start_time;
    // printf("%ld\n", get_time());
    return timestamp;
}

// pravdepodobne to blbne kvuli tomu ze ten gettime se musi udelat custom
void *philo_loop(void *arg)
{
    thread_data_t data = *(thread_data_t *)arg;
    t_table *table = data.table;
    int id = data.id;

    if (id % 2 == 0)
    {
        // printf("waiting for %ld ms - philo %d\n", table.eat_time, id);
        usleep(table->eat_time);
    }
    // while (porad zije)

    // printf("Philosopher %d timestamp: %ld, start time: %ld\n", id, get_timestamp(table), table.start_time);

    pthread_mutex_lock(&table->fork_mutex[id]);
    printf("%ld %d has taken a fork\n", get_timestamp(table), id);
    if (id == table->philo_count)
        pthread_mutex_lock(&table->fork_mutex[0]);
    else
        pthread_mutex_lock(&table->fork_mutex[id + 1]);
    printf("%ld %d has taken a fork\n", get_timestamp(table), id);
    printf("%ld %d is eating\n", get_timestamp(table), id);
    usleep(table->eat_time);
    pthread_mutex_unlock(&table->fork_mutex[id]);
    if (id == table->philo_count)
        pthread_mutex_unlock(&table->fork_mutex[0]);
    else
        pthread_mutex_unlock(&table->fork_mutex[id + 1]);
    printf("%ld %d is sleeping\n", get_timestamp(table), id);
    usleep(table->sleep_time);
    printf("%ld %d is thinking\n", get_timestamp(table), id);
    return NULL;
}

int run_sim(t_table table)
{

    int i = 0;

    table.start_time = get_time();
    //printf("Simulation start time: %ld\n", table.start_time);
    while (i < table.philo_count)

    {
        pthread_mutex_init(&table.fork_mutex[i], NULL);
        thread_data_t *data = malloc(sizeof(thread_data_t));
        data->id = i;
        data->table = &table;
        // printf("Thread data: id = %d, table.philo_count = %d\n", data->id, data->table.philo_count);
        pthread_create(&table.philos[i].thread, NULL, philo_loop, data);
        i++;
    }
    i = 0;
    while (i < table.philo_count)
    {
        pthread_join(table.philos[i].thread, NULL);
        i++;
    }
    return SUCCESS;
}

int main(int argc, char **argv)
{
    t_table table;
    if (argc < 5 || argc > 6)
        return (msg("Error: Invalid number of arguments\n", EXIT_FAILURE));

    if (!parse_args(argc, argv))
        return (msg("Error: Parsing error\n", EXIT_FAILURE));

    table = init_structs(argc, argv);
    if (table.philo_count == 0)
        return (msg("Error: Init error\n", EXIT_FAILURE));

    run_sim(table);
}

/*
bezi loop dokud neni nekdo mrtvy nebo [number_of_times_each_philosopher_must_eat] je splneno
postupne vytvorim vsechny thready
kazdy philosopher ma svoje 2 fork_mutexy, ktere zapne na urcitou dobu
potom spi urcitou dobu


*/