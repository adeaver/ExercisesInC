## Homework 4

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/adeaver/ExercisesInC/tree/master/exercises/ex03)

[Here is a link to the ex04 directory in my repository](https://github.com/adeaver/ExercisesInC/tree/master/exercises/ex04)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

File systems give the abstraction that an entry is a mapping between a file name and its contents. As well as the abstraction that the contents of a file is a sequence of bytes. In its implementation, it's not so much a sequence of bytes but represented as 4KB blocks.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

Some of the information that could be stored in the `OpenFileTableEntry` is the current offset being read, the location of the block, and part of the current block in memory. 

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

The OS can switch from task to task while it waits for disk storage. It can also do block transfers (loading a whole block), prefetching (which is predicting which blocks will need to be read), buffering (only writing to the block when it needs to), and caching. 

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

The CPU could have been buffering, which means that it was waiting to store a file by holding it in memory to save time. In this case, the file is stored in memory and not yet on disk.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

One advantage of inode over FAT is that seeking a file is not stupidly slow because files are more or less continuous in the inode system.

6) What is overhead?  What is fragmentation?

Overhead is a measure of how much space the allocator and metadata take up in addition to the actual content of the file. Fragmentation is the unused or partially used space.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

The principle that everything is a file makes developers' lives easier because it means that there is pretty much one standard protocol (API) to work with. It can be a bad idea because it might end up creating a bad abstraction for something like a directory which is actually just a file that contains metadata.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).



