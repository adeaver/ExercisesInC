/*
 * This program allows the user to enter integers, one per line, 
 * until the user hits Control-D, which is the end-of-file (EOF) character.
 *
 * Andrew Deaver
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define BUFFER_SIZE 10
#define NUM_ARRAY_SIZE 5 

/*
 * This function flushes the input buffer in the case
 * that the input exceeds the length of the buffer
 *
 * input: the variable to store the input
 *
 * returns error code. If the first character is a 
 * carriage return, then the input did not exceed the length
 * of the buffer so return 0, if it is not 10, then there's an error
 * and the buffer needs to be flushed.
 * It will return 2 if the buffer starts with EOF.
 * TODO: Fix this to work with any string that contains EOF.
 */
int flush_input() {
	int c = getchar();
	if(c == 10) {
		return 0;
	}
	if(c == EOF) {
		return 2;
	}
	do {
		c = getchar();
	} while(c != 10);
	return 1;
}

/*
 * Checks to see if every value in the input is
 * numeric
 *
 * returns 0 if it's safe, and 1 if it's not
 */
int check_value(char *input) {
	int i;
	int stop = strlen(input);
	for(i = 0; i < stop; i++) {
		if(input[i] < 48 || input[i] > 57) {
			return 1;
		}
	}	
	return 0;
}

/* This function gets the user input
 * 
 * input: the variable to store the input
 *
 * returns the error code from flush_input
 */
int get_input(char *input) {
		puts("Enter a number: ");
		scanf("%9s", input);
		return flush_input();
}

/*
 * This function converts the input from a string
 * to an integer using atoi
 *
 * returns an error code
 */
int convert_value(char *input, int *val) {
	int err = check_value(input);
	if(err) {
		return 1;			
	}
	*val = atoi(input); 
	return 0;
}

/*
 * This function adds the elements of an array
 *
 * array - the array to add
 * max - the highest element of the array
 *
 * returns the sum of all the elements of an array
 */
int add_array(int array[], int max) {
	int res = 0;
	int i;
	for (i = 0; i < max; i++) {
		res += array[i];
	}
	return res;
}

int main() {
	int error;
	int current_num = 0;
	int *val;
	val = malloc(sizeof(int));
	char number[BUFFER_SIZE];
	int num_array[NUM_ARRAY_SIZE];
	while(1) {
		error = get_input(number);
		if (error) {
			if(error == 2) {
				int res = add_array(num_array, current_num);
				printf("The value of all the elements of the array is: %d\n", res);	
				return 0;
			}
			puts("Input exceeded length of buffer");
			continue;
		}
		error = convert_value(number, val);
		if(error) {
			puts("Cannot Convert Value, Please Enter A Number");
			continue;
		}
		if(current_num >= (NUM_ARRAY_SIZE-1)) {
			puts("You have exceeded the number of elements in the array, goodbye");
			return 0;
		}
		num_array[current_num] = *val;
		current_num++;
	}
	return 0;
}
