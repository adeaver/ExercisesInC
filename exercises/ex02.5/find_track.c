/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5
#define NUM_MATCHES 10

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    // TODO: fill this in
	regex_t regex;
	int status = regcomp(&regex, pattern, REG_EXTENDED);
	if (status != 0) {
		puts("There was an error processing your search term.");
		return;
	}
	int i;
	int nomatch;
	regmatch_t m[NUM_MATCHES];
	for (i = 0; i < NUM_TRACKS; i++) {
		nomatch = regexec (&regex, tracks[i], NUM_MATCHES, m, 0);
		if (!nomatch) {
            printf("Track %i: '%s'\n", i, tracks[i]);
		}
	}
	regfree(&regex);
	return;
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);
	
    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
