## Homework 8

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex08 directory in my repository](https://github.com/adeaver/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

The kernel's most basic task is to handle interrupts.

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

The hardware saves the program counter and the flag register in memory.

3) What is the difference between an interrupt and a context switch?

An interrupt is a signal given by a program. A context switch is when the kernel decides to switch to another process after an interrupt.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

When an operation that cannot complete immediately, like a disk request, completes. The process that was blocked because it was waiting for the disk request to complete is changed from blocked to ready.

5) Why might a scheduler want to give higher priority to an I/O bound process?

A scheduler might give higher priority to an I/O bound process because it'll have a lot of time to wait, so it can run that first, complete different processes, and then return to the I/O bound process later.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices. 
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; 
this is really how I make French toast.)

Put 8 slices on, cook both sides, and then put the other four slices on. That's 40 minutes of French Toast making.

