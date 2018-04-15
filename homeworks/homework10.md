## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/adeaver/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

A data structure is thread safe if multiple threads can access the data structure and not leave the data structure in an inconsistent state. 

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

So that next_in and next_out don't make the queue appear empty.

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

One producer could access the array when next_in is 0. It can prepare to push something to the array in this position, but before that happens, another producer could access the array when next_in has not been modified. In this scenario, both producers would put an element in the first position of the array. Similarly, it's possible that next_in could increment to 2 and not 1 in this case.

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

Otherwise the producer would never be able to access the queue.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

We're definitely sure that the queue is not empty. We're probably sure that the queue is safe to access.

6) What happens if you signal a condition variable when there are no waiting threads?

The signal has no effect.

7) Do you have to lock the mutex to signal a condition variable?

Yes.

8) Does the condition have to be true when you signal a condition variable?

Not necessarily.




