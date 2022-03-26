## Summary

This project is an introduction of thread.

The project is animated by the problem of the philosopher. : https://en.wikipedia.org/wiki/Dining_philosophers_problem

![dwqeqwe](https://user-images.githubusercontent.com/76008303/160246456-8b22937e-8e33-469f-88ec-4b088805b7cd.png)

Full subject :

[en.subject.pdf](https://github.com/Chafik42/Philosophers/files/8355767/en.subject.pdf)

## Subject

![Philosopher](https://user-images.githubusercontent.com/76008303/160246370-355557b1-4940-4259-811c-023a6aa02fb1.png)

Imagine 5 philosophers seated around a table, with a large bowl of spagetti in the middle,
each philosopher has, on his right, a fork.

And there are 3 rules, 
the time to die if a philosopher has nothing to eat (in millisecond)
the time it takes to eat (in millisecond)
and the time it takes to sleep right after eating, (in millisecond)
And optionally, the number of times a philosopher must eat to end the simulation (a number)

A philosopher need 2 fork to eat the spagetti, this means taking the fork of another philosopher, and so making some of the philosopher wait.

The goal is to reproduce, with a lot of precision, this simulation, you will be able to change the rules.

For a more precise explanation go back to this link https://en.wikipedia.org/wiki/Dining_philosophers_problem

To reach such a result, we will have to use thread, and make them communicate each other using mutex.

A very helpfull video can explain that : https://www.youtube.com/watch?v=uA8X5zNOGw8&ab_channel=JacobSorber

There is also some alternative of the thread, like fork, or semaphore.

## Usage

> make

> ./philo (number of philosophers) (time_to_die in ms) (time_to_eat in ms) (time_to_sleep in ms) (Optionnaly number_of_times_each_philosopher_must_eat)

## Example

![wqewqewqeee](https://user-images.githubusercontent.com/76008303/160247134-61f7a207-cf8f-4bd9-b6e4-eda3110c0e56.png)

## Note

![wqewqeee](https://user-images.githubusercontent.com/76008303/160247149-b495f581-0f98-4bca-a014-3eb535ae6d14.png)
