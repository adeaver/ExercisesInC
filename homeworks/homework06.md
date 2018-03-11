## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/adeaver/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

I would expect `malloc` and `free` to be constant time since they probably just return references to memory that's free. I would expect `calloc` and `realloc` take time proportional to the size of the allocated chunk. 

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

Ideally, you'd get a segfault. But more than likely, you'll end up reading whatever was there before.

b) Writing to unallocated memory.

You could possibly overwrite internal data structures for `free` and `malloc` and cause serious issues later in the execution of your program.

c) Reading from a freed chunk.

Similar to reading from unallocated memory, you'd ideally get a segfault, but you can also read whatever was there (or whatever is there now).

d) Writing to a freed chunk.

Similar to writing from unallocated memory, you can overwrite some really important things in your program.

e) Failing to free a chunk that is no longer needed.

You can cause a memory leak. Mostly, this isn't an issue, but for longer running programs, you might run out of physical memory or start leaking memory on disk. The major result of this is that malloc will eventually return NULL.

3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

The current winners (or losers) are a process meant for software updates (on mac), Chrome (unsurprisingly), and Slack (of course).

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

You waste a lot of memory since it has to allocate memory in 16 byte chunks, so if you allocate like 100 things with a size of 4 bytes, you'll end up using 1.6 KB instead of 400 bytes. You can allocate them in arrays to mitigate this problem.

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
