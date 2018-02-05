## Homework 2

### C Exercises

Modify the link below so it points to the `ex02` directory in your
student repository.

[Here is a link to the ex02 directory in my repository](https://github.com/adeaver/ExercisesInC/tree/master/exercises/ex02)

### Think OS Chapter 2 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1. Give a real-world example of virtualization (ideally not one of 
the ones in the book).  What is abstractly true about the system that
is not literally true about the implementation?

Amazon provides a great example of virtualization. It lends itself to this idea that there is an infinite collection of items in a warehouse somewhere, but in reality, Amazon may have to ship some items between distribution centers. It doesn't happen as much as it used to, but I've still gotten messages that packages have to be delivered separtely.

2. What is the difference between a program and a process?

A process is an object that represents everything about the state of a program, which is more like a logical set of operations. A process is like an object in Java that contains a main function, where the main function is the program.

3. What is the primary purpose of the process abstraction? 

The purpose of process abstraction is to simplify the job of the developer by not worrying developers about how things like virtual memory or multithreading actually work under the hood. The idea is that the process is completely isolated, even if it isn't.

4. What illusion does the process abstraction create?

The illusion that process abstraction creates is that every process has its own set of memory and dedicated hardware to run uninterrupted.

5. What is the kernel?

The kernel is responsible for all the core capabilities of the operating system.

6. What is a daemon?

A Daemon is a process that run in the background and provide operating system services.
