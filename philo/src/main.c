/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:23:40 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/01 16:21:32 by tomasklaus       ###   ########.fr       */
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

int is_alive(t_table *table, int id)
{
    printf("Timestamp: %ld, Current time: %ld, Difference: %ld\n", table->philos[id].last_meal, get_time(), get_time() - table->philos[id].last_meal);
    if ((get_time() - table->philos[id].last_meal) > table->die_time)
        return ERROR;
    return SUCCESS;
}


void *philo_loop(void *arg)
{
    thread_data_t data = *(thread_data_t *)arg;
    t_table *table = data.table;
    int id = data.id;
    int count = 0;

    if ((id+1) % 2 == 0)
    {
        //printf("%ld %d is thinking\n", get_timestamp(table), id);
        usleep(50);
    }
    table->philos[id].last_meal = get_time();
    while (is_alive(table, id) && (table->must_eat_count == 0 || count < table->must_eat_count))
    {
        pthread_mutex_lock(&table->fork_mutex[id]);
        printf("%ld %d has taken a fork\n", get_timestamp(table), id);
        if (id == table->philo_count)
            pthread_mutex_lock(&table->fork_mutex[0]);
        else
            pthread_mutex_lock(&table->fork_mutex[id + 1]);
        printf("%ld %d has taken a fork\n", get_timestamp(table), id);
        printf("%ld %d is eating\n", get_timestamp(table), id);
        usleep(table->eat_time);
        table->philos[id].last_meal = get_time();
        pthread_mutex_unlock(&table->fork_mutex[id]);
        if (id == table->philo_count)
            pthread_mutex_unlock(&table->fork_mutex[0]);
        else
            pthread_mutex_unlock(&table->fork_mutex[id + 1]);
        printf("%ld %d is sleeping\n", get_timestamp(table), id);
        usleep(table->sleep_time);
        printf("%ld %d is thinking\n", get_timestamp(table), id);
        count++;
    }
    return NULL;
}

int run_sim(t_table table)
{

    int i = 0;

    table.start_time = get_time();
    // printf("Simulation start time: %ld\n", table.start_time);
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

observer thread kterej nonstop checkuje u kazdyho philosofera last_meal_time (bude potreba mutex na last_meal_time)
kdyz nejakej presahne ten cas nebo budou vsichni najezeni, tak da stop flag a printne se ktery philosopher umrel



*/