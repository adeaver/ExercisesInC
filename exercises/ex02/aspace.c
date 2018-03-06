/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void allocate() {
	void *z = malloc(128);
    printf ("Address of z is %p\n", z);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(27);
	void *x = malloc(27);
    char *s = "Literal string";
    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of p is %p\n", p);
    printf ("Address of x is %p\n", x);
    printf ("Address of s is %p\n", s);
	allocate();

    return 0;
}
