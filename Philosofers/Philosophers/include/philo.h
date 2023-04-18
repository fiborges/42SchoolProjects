#ifndef PHILO_H
#define PHILO_H

// Libraries required for the program to function
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

// Constants for error messages
#define ALLOC_ERR_1 "ERROR WHILE ALLOCATING THREADS IDs"
#define ALLOC_ERR_2 "ERROR WHILE ALLOCATING FORKS"
#define ALLOC_ERR_3 "ERROR WHILE ALLOCATING PHILOS"
#define ERR_IN_1 "INVALID INPUT CHARACTER"
#define ERR_IN_2 "INVALID INPUT VALUES"
#define TH_ERR "ERROR WHILE EATING THREADS"
#define JOIN_ERR "ERROR WHILE JOINING THREADS"
#define INIT_ERR_1 "ERROR WHILE INIT FORKS"
#define TIME_ERR "UNABLE TO RETRIVE UTC"

// Constants for color-coded messages
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Constants for philosopher actions
#define TAKE_FORKS BLUE"has taken a fork"RESET
#define THINKING MAGENTA"is thinking"RESET
#define SLEEPING YELLOW"is sleeping"RESET
#define EATING GREEN"is eating"RESET
#define DIED RED"died"RESET

// Structure representing a philosopher
typedef struct s_philo
{
    struct s_data      *data;
    pthread_t           thread;
    int                 id;
    int                 meals_eaten;
    int                 is_alive;
    int                 is_eating;
    uint64_t            time_to_die;
    pthread_mutex_t     lock;
    pthread_mutex_t     *right_fork;
    pthread_mutex_t     *left_fork;
}   t_philo;

// Structure representing simulation data
typedef struct s_data
{
    pthread_t           *thread_ids;
    int                 nb_of_philos;
    int                 nb_of_meals;
    int                 is_dead;
    int                 finished;
    t_philo             *philos;
    u_int64_t           death_time;
    u_int64_t           time_to_eat;
    u_int64_t           time_to_sleep;
    u_int64_t           start_time;
    pthread_mutex_t     *forks;
    pthread_mutex_t     lock;
    pthread_mutex_t     write_mutex;
}   t_data;

// Function prototypes
// Function prototypes

// Convert string to long integer
long        ft_atoi(const char *str);

// Display error message and free allocated memory, if applicable
int         error(char *str, t_data *data);

// Compare two strings, return 0 if they are equal
int         ft_strcmp(char *s1, char *s2);

// Print a message related to a philosopher's action
void        print_message(char *str, t_philo *philo);

// Clean up resources and exit the program
void        exit_program(t_data *data);

// Handle the case of a single philosopher simulation
int         single_philosopher_simulation(t_data *data);

// Clean up and free allocated resources
void        clear_data(t_data *data);

// Get the current time in microseconds
u_int64_t   get_current_time(void);

// Sleep for a specified amount of time (microseconds) without blocking other threads
int         controlled_sleep(useconds_t time);

// Initialize the simulation with data from command line arguments
int         initialize_simulation(t_data *data, char **argv, int argc);

// Initialize threads for philosophers
int         initialize_threads(t_data *data);

// Validate that command line arguments are numeric
int         validate_numeric_arguments(char **argv);

// Philosopher's eating behavior
void        eating(t_philo *philo);

// Function executed by each philosopher thread, simulating their behavior
void        *philosopher_behavior(void *philo_pointer);

#endif