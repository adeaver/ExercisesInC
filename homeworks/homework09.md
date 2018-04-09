## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/adeaver/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?

To protect threads from access each other's data and causing inconsistency between threads.

2) What does the gcc flag `-lpthread` do?

It compiles the code with the pthread library.

3) What does the argument of `pthread_exit` do?

It passes a value to the thread that joins with the thread that calls pthread_exit.

4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?

Any thread can join any other thread, so nothing happens.

5) What goes wrong if several threads try to increment a shared integer at the same time?

You can get an inconsistent answer. For instance, a counter initialized to zero might be incremented three times, but the value written might still be 1 since the threads initially read it at zero.

6) What does it mean to "lock a mutex"?

It bars all other threads from doing something.
