<div align="center">

# Philosophers

_I never thought philosophy would be so deadly_

Dining philosophers problem's solution for 42 cursus project

</div>

## The Dining Philosophers Problem

The Dining Philosophers problem is a classic synchronization problem that was first introduced by Edsger W. Dijkstra in 1965. The problem consists of `n` philosophers sitting around a round table with one chopstick between each of them. There is a large bowl of spaghetti in the center of the table, and each philosopher must eat from the bowl.

The philosophers spend their time thinking and eating. In order to eat, a philosopher needs to pick up the two chopsticks that are adjacent to them. However, they can only pick up one chopstick at a time. If a philosopher cannot pick up both chopsticks, they must wait for one to become available. The problem is to design a protocol that ensures that each philosopher gets a chance to eat without causing a deadlock.

## Solution Approach

The solution implemented in this project uses the C programming language and pthreads for thread synchronization. The following steps were taken to solve the Dining Philosophers problem:

1. Define data structures for philosophers and simulation data.
2. Parse and validate command line arguments.
3. Initialize the simulation by allocating resources and initializing mutexes.
4. Create a separate thread for each philosopher.
5. Implement the philosopher behavior function, which includes thinking, eating, and sleeping.
6. Synchronize access to shared resources (chopsticks) using mutex locks.
7. Monitor the philosophers' states and print relevant messages.
8. Clean up and free allocated resources when the simulation is finished.

The provided code snippet includes the header file, which contains the data structures, constants, and function prototypes used in the solution.

## How to Compile and Run

To compile the project, use the following command:
-> make
-> ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_each_philosopher_must_eat]


