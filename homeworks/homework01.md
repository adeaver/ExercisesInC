## Homework 1

### C Exercises

[Here is a link to the ex01 directory in my repository](https://github.com/adeaver/ExercisesInC/tree/master/exercises/ex01)

### Think OS Chapter 1 reading questions

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Dynamic typing, which is checking the type of variables at runtime as opposed to at compile time, is a feature that is common in interpreted languages like Python, but not common in compiled langauges.

2) Name two advantages of static typing over dynamic typing.

Static types allow for faster execution because they handle all checks at compilation time, instead of having to take time while running to check the variable types. Additionally, this compilation time check leads to an increase in space, since the program doesn't have to save variable names. A bonus is that it allows you to avoid type errors in untested code, since these functions will fail to compile if they contain type errors.

3) Give an example of a static semantic error.

int num = "300"; would generate a static semantic error since you're trying to assign a string to an int variable. These are the errors that occur during static type checking.

4) What are two reasons you might want to turn off code optimization?

High levels of optimization make the compilation process slower. This is especially true in larger programs. Also, it may exacerbate bugs. Generally, optimization at the lowest level makes "safe" optimizations. Turning on high levels of optimization may change the behavior of your program if you have a mistake in your code by making "unsafe" optimzations..

5) When you run `gcc` with `-S`, why might the results look different on different computers?

The -S flag generates assembly code which is generated specifically or the machine you are running.

6) If you spell a variable name wrong, or if you spell a function name wrong, 
the error messages you get might look very different.  Why?

These error messages are coming from different steps in the compilation process. For example, the linker may send an error if you spell a function name wrong but the preprocessor might give you an error from spelling a variable name wrong.

7) What is a segmentation fault?

A segmentation fault is a run-time error in which you read or write an incorrect location in memory.
