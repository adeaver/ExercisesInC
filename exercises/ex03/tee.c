/* tee.c - A C program that implements the basic functionality of the UNIX command 'tee'
 *
 * Andrew Deaver
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STDIN_END 1
#define READ_ERROR 2

/* This function reads the next char out of STDIN
 *
 * bufferChar - the one character buffer
 *
 * returns an error code based on the result:
 * STDIN_END (1) - the STDIN is empty
 * READ_ERROR (2) - there was an error reading STDIN
 * 0 - no error occurred
 */
int readNextChar(char *bufferChar) {
	int bytesRead = read(0, bufferChar, 1);
	switch(bytesRead) {
		case -1:
			return READ_ERROR;
		case 0:
			return STDIN_END;
		default:
			return 0;
	}
}

/* This function writes the next char to the file
 *
 * bufferChar - the one character buffer
 * fp - the file to write to
 *
 * returns an error code based on the the result:
 * 0 - no error
 * 1 - error writing
 */
int writeNextChar(char *bufferChar, FILE *fp) {
	int res = fputc(*bufferChar, fp);
	return res;
}

int main(int argc, char *argv[]) {
	if(argc < 2) {
		puts("Need to include a file name");
		return 1;	
	}
	FILE *fp = fopen(argv[1], "ab+");
	if(!fp) {
		puts("Error creating file");
		return 1;
	}	
	char *buffer = malloc(sizeof(int));
	int readResult = readNextChar(buffer);
	int writeResult = 0;
	while(readResult != STDIN_END && readResult != READ_ERROR) {
		writeResult = writeNextChar(buffer, fp);
		if(writeResult == EOF) {
			puts("Error writing file");
			break;				
		}
		readResult = readNextChar(buffer);
	}
	int res = fclose(fp);
	return res;
}
