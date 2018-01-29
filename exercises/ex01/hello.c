#include <stdio.h>

int main() {
	// Adding 5 to see if this variable
	// appears with and without optimization
	int x = 5;
	int a = 3;
	int b = 4;
	int c = a + b;
	// Create variable to essentially shadow
	// x variable for optimization test
	int y = x + 1;
	// Print y and shadow x
	printf("Value of y: %d\n", y);
	printf("c is %d\n", c);
	printf("Hello, World!\n");
	if (c%2 == 0) {
		printf("c is even!\n");
	} else {
		printf("c is odd!\n");
	}
	return 0;
}
