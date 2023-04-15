<h1 align="center">
	🍜 Philosophers
</h1>

<p align="center">
	<b><i>Concurrency and synchronization in action</i></b><br>
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about-the-problem">The Problem</a>
	<span> · </span>
	<a href="#-solution-approach">Solution Approach</a>
	<span> · </span>
	<a href="#-how-to-compile-and-run">How to Compile and Run</a>
</h3>

---

## 💡 About the Problem
[![42](https://img.shields.io/badge/BornToCode-3_Circle-00babc?style=flat-square&logo=42)](https://42seoul.kr/)
)

> _The Dining Philosophers problem is a classic synchronization problem that was first introduced by Edsger W. Dijkstra in 1965. The problem consists of `n` philosophers sitting around a round table with one chopstick between each of them. There is a large bowl of spaghetti in the center of the table, and each philosopher must eat from the bowl._
	_The philosophers spend their time thinking and eating. In order to eat, a philosopher needs to pick up the two chopsticks that are adjacent to them. However, they can only pick up one chopstick at a time. If a philosopher cannot pick up both chopsticks, they must wait for one to become available. The problem is to design a protocol that ensures that each philosopher gets a chance to eat without causing a deadlock._

## 🛠 Solution Approach
- Define data structures for philosophers and simulation data.
- Parse and validate command line arguments.
- Initialize the simulation by allocating resources and initializing mutexes.
- Create a separate thread for each philosopher.
- Implement the philosopher behavior function, which includes thinking, eating, and sleeping.
- Synchronize access to shared resources (chopsticks) using mutex locks.
- Monitor the philosophers' states and print relevant messages.
- Clean up and free allocated resources when the simulation is finished.

## 📚 How to Compile and Run
To compile the project, use the following command:
--> make
--> ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_each_philosopher_must_eat]


