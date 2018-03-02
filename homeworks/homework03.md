## Homework 3

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/adeaver/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

You would need 6 bits to specify a letter in an alphabet consisting of 33 letters. This is because 5 bits would give us `2^5 = 32` which is too few. 6 bits gives us `2^6 = 64`.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

2^32 = 4,294,967,296.

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

Memory is short term and volatile. It does not perserve state after shutdown. Storage is not volatile, it it meant for long-term storage but requires more time to access.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

GiB is a binary multiple of bytes, whereas GB is a decimal multiple of bytes. 1 GiB is 1024^3 bytes, whereas 1 GB is 1000^3 bytes. This means that 1 GiB is 2.4% larger.

5) How does the virtual memory system help isolate processes from each other?

Processes don't have to worry about how they're accessing physical memory. They are given a virtual address which the CPU and OS organize and translate into the physical addresses.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

Because it's impossible to tell how much stack and heap space are necessary, they grow towards each other. This maximizes the space between them.

7) What Python data structure would you use to represent a sparse array?

Depending on the data that I'm storing, I'd try to store it in a dictionary.

8) What is a context switch?

A context switch is a mechanism through which an operating system can interrupt one process, save its state, and then run another.
