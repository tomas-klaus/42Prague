/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:21:47 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/15 12:46:56 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H
#include <string.h>   // memset
#include <stdio.h>    // printf
#include <stdlib.h>   // malloc, free
#include <unistd.h>   // write, usleep
#include <sys/time.h> // gettimeofday
#include <pthread.h>  // pthread_create, pthread_mutex_init ...
#include <limits.h>

#define SUCCESS 1
#define ERROR 0

/******************************************************************************
 *                                 Structures                                  *
 ******************************************************************************/

typedef struct s_philo
{
    int id;
    int fork[2];
    int times_ate;

    pthread_mutex_t times_ate_mutex;
    pthread_mutex_t last_meal_mutex;
    time_t last_meal;

    pthread_t thread;

} t_philo;

typedef struct s_table
{
    int philo_count;
    time_t die_time;
    time_t eat_time;
    time_t sleep_time;
    time_t start_time;
    int must_eat_count;
    int stop_flag;

    pthread_mutex_t write_lock;
    pthread_mutex_t stop_flag_mutex;
    pthread_mutex_t *fork_mutex;

    pthread_t obs_thread;

    t_philo *philos;
} t_table;

typedef struct
{
    t_table *table;
    int id;
} thread_data_t;

/******************************************************************************
 *                           Function Prototypes                               *
 ******************************************************************************/

// parsing
int parse_args(int argc, char **argv);
int ft_safe_atoi(const char *str, int *error);

// init
t_table init_structs(int argc, char **argv);

// exit
int msg(char *str, int exit_no);
void cleanup(t_table table);

// time
time_t get_time();
time_t get_timestamp(t_table *table);
int philo_sleep(t_table table, time_t sleep_time, int id);
void setup_times(t_table *table);

//observer
void *obs_loop(void *arg);

//philo
void *philo_loop(void *arg);

#endif