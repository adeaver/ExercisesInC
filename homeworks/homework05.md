## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/adeaver/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

Assuming that the number is still an unsigned int, you would get 65408, instead of 128. If the new 16-bit number is now a signed number, you would get -128.

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

`(UINT_MAX ^ x) + 1` will return the two's complement of any number `x`. This is because UINT_MAX is a 32-bit integer with all ones, and taking the XOR flips all the bits. Adding 1 is the two's complement.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

It's so that written out, smaller numbers occur before larger numbers lexicographically. 

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

The binary representation would be `01000001010100000000000000000000` which is `1095761920` as an unsigned int.

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit. 

The function I wrote is

`
char* bitshift_lower(char* str) {
	int len = strlen(str);
	char* newstr = malloc(len * sizeof(char));
	int i;
	for(i = 0; i < len; i++) {
		newstr[i] = str[i] | 32;
	}
	return newstr;	
}
` 
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



