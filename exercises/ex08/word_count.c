#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NO_ERROR 0
#define ERROR 1
#define NUM_MATCHES 1
#define LOWERCASE_SHIFT 32

regex_t punctuation_regex;
char *punctuation = "^[A-Za-z ]";

char* read_line(FILE *file, int *status) {
	char * line = NULL;
    size_t len = 0;
    ssize_t read;
	if((read = getline(&line, &len, file)) == -1) {
		*status = ERROR;
	} else {
		*status = NO_ERROR;
	}
	return line;
}

char* clean_string(char *str) {
	int len = strlen(str);
	char *new_str = malloc(sizeof(char) * len);
	int j = 0;

	int i;
	int match;
	regmatch_t m[NUM_MATCHES];
	for (i = 0; i < len; i++) {
		match = regexec(&punctuation_regex, &(str[i]), NUM_MATCHES, m, 0);
		if(!match) {
			if(str[i] >= 97 || str[i] == 32) {
				new_str[j] = str[i];
			} else {
				new_str[j] = (str[i] + LOWERCASE_SHIFT);
			}
			j++;
		}
	}
	new_str[j] = '\0';
	return new_str;
}

int count_words(char *str) {
	int len = strlen(str);
	int word_count = 0;
	int in_word = 0;
	for(int i = 0; i < len; i++) {
		if(!in_word && str[i] != 32) {
			in_word = 1;
		}
		if(in_word && str[i] == 32) {
			word_count++;
			in_word = 0;
		}
	}
	if(in_word) {
		word_count++;
	}
	return word_count;
}

char** split_words(char *str) {
	int word_count = count_words(str);
	char **words = malloc(sizeof(char*) * word_count);
	int j = 0;
	printf("%s\n", str);
	char* word = strtok(str, " ");
	while(word != NULL) {
		if (word[0] >= 97) {
			words[j] = word;
			j++;
		}
		word = strtok(NULL, " ");
	}	
	return words;
}

char** get_words(FILE *file, int *status) {
	char* line = read_line(file, status);
	char* cleaned_line = clean_string(line);
	return split_words(cleaned_line);
}

int main() {
	int status = regcomp(&punctuation_regex, punctuation, REG_EXTENDED);
	FILE *metamorphosis = fopen("./metamorphosis.txt", "rb");
	char **words;
	int len;
	while(status == NO_ERROR) {
		words = get_words(metamorphosis, &status);
	}	
	return 0;
}
