## Homework 7

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

When you write a new value into the program counter, the program jumps or branches to that instruction.

2) What is the fundamental problem caches are meant to solve?

The cache serves to eliminate idle time in the CPU by serving as a very quick way to access data.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

When the hit rate is 50%, the average access time is given by .5 * 1 ns + .5 * 10 ns = 5.5 ns.
When the hit rate is 90%, the average access time is given by .9 * 1 ns + .1 * 10 ns = 1.9 ns.

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

One thing that could possibly increase spatial locality is a union. Especially when performing bitwise calculations.
Sparse arrays like hash maps would decrease locality because they would probably load a lot of empty data into the cache.

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

"Cache Aware" typically refers to a specific architecture and hardware, so a program with better locality is not considered "cache aware."

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

About $20-$30 per MB.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

Because the time cost to access memory at the bottom of the hierarchy is sizeable.

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Prioritize processes in such a way that processes with large cache needs are not run at the same time.
