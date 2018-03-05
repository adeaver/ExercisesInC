#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* bitshift_lower(char* str) {
	int len = strlen(str);
	char* newstr = malloc(len * sizeof(char));
	int i;
	for(i = 0; i < len; i++) {
		newstr[i] = str[i] | 32;
	}
	return newstr;	
}

int main() {
	int x = 12;
	int y = (UINT_MAX ^ x) + 1; 
	printf("XOR on x returns %d\n", y);
	char* str = bitshift_lower("HELLO");
	printf("The result is %s\n", str);
	return 0;	
}
