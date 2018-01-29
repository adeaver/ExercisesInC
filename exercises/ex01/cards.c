/*
 * cards.c
 *
 * A program that emulates a card game in which
 * the user enters a card and the program keeps
 * score
 *
 * Andrew Deaver
 */
#include <stdio.h>
#include <stdlib.h>

/* This function gets the user input
 * 
 * input: the variable to store the input
 */
void get_input(char *input) {
		puts("Enter the card_name: ");
		scanf("%2s", input);
}

/* Converts the value of a card name char
 * to an int which is used to score the game
 *
 * card_name: the char used to represent the card
 * val: the value of the card
 */
void get_value(char card_name, int *val) {
	switch(card_name) {
		case 'K':
		case 'Q':
		case 'J':
			*val = 10;
			break;
		case 'A':
			*val = 11;
			break;
		case 'X':
			*val = 0;
			break;	
		default:
			*val = atoi(&card_name);
			if ((*val < 1) || (*val > 10)) {
				puts("I don't understand that value");
				*val = -1;	
			}
	}
}

int main() {
	int count = 0;
	char card_name[3];
	int *val;
	val = malloc(sizeof(int));
	do {
		get_input(card_name);
		get_value(card_name[0], val);	
		if((*val > 2) && (*val < 7)) {
			count++;
		} else if (*val == 10) {
			count--;
		} else if (*val == -1) {
			continue;
		}
		printf("Current count: %i\n", count); 
	} while(card_name[0] != 'X');
	return 0;
}
