/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:21:47 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/08/20 18:56:19 by tomasklaus       ###   ########.fr       */
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

    // pthread_mutex_t meal_time_lock;

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

    pthread_mutex_t *fork_mutex;

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

// time
time_t get_time();
time_t get_timestamp(t_table *table);

#endif