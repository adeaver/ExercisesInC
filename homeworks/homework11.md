## Homework 11

### C Exercises

Modify the link below so it points to the `ex11` directory in your
student repository.

[Here is a link to the ex11 directory in my repository](https://github.com/adeaver/ExercisesInC/tree/master/exercises/ex11)

### Think OS Chapter 11 reading questions

1) Why is is a bad idea to pass a `sem_t` as a parameter?

There is no definition in POSIX for the behavior of a copy. Copying a semaphore could therefore leave it in an inconsistent state.

2) When you use a Semaphore as a mutex, what should its initial value be?

It's initial value should be 1 to indicate that it is unlocked.

3) Can you think of another use for a Semaphore where you might use a different initial value?

You could use it as a resource counter, which you want to initialize it to 0.

4) In my solution to the producers-consumers problem using Semaphores,
what does it mean if the value of `queue->spaces` is `3` at some point in time?

There are 3 empty spaces in your queue and nothing is working on it.

5) What does it mean if `queue->space` is `-3`?

There are 3 threads waiting to use the queue.

6) Why doesn't `queue_pop` have to use `queue_empty` to check whether the queue is empty?

It's blocked until queue_items is zero.

7) Any problem that can be solved with Semaphores can also be solved with mutexes and condition variables.
How can you prove that that's true?

Implement a semaphore using mutexes and conditional variables.

8) What is Property 3?  Hint: see *The Little Book of Semaphores*, 
[Section 4.3](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf). 

If there are threads waiting on a semaphore when a
thread executes signal, then one of the waiting threads has to be
woken.


