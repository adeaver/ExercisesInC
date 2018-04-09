/* Example from Head First C.

Downloaded from https://github.com/twcamper/head-first-c

Modified by Allen Downey.
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void rss_feed_print(char* rss_feed, char* search_phrase, const char* PYTHON, const char* SCRIPT) {
    char var[255];
	sprintf(var, "RSS_FEED=%s", rss_feed);
	char *vars[] = {var, NULL};

	int res = execle(PYTHON, PYTHON, SCRIPT, search_phrase, NULL, vars);
	if (res == -1) {
		error("Can't run script.");
	}
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <search phrase>\n", argv[0]);
        return 1;
    }
    const char *PYTHON = "/usr/bin/python2.6";
    const char *SCRIPT = "rssgossip.py";
    char *feeds[] = {
        "http://www.nytimes.com/services/xml/rss/nyt/Africa.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/Americas.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/MiddleEast.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/Europe.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/AsiaPacific.xml"
    };
    int num_feeds = 5;
    char *search_phrase = argv[1];

    pid_t pid;
    for (int i=0; i<num_feeds; i++) {
		pid = fork();

		if (pid == 0) {
			rss_feed_print(feeds[i], search_phrase, PYTHON, SCRIPT);
			exit(0);
		}
    }
    
	int status;
    for (int i=0; i<num_feeds; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        status = WEXITSTATUS(status);
        //printf("Child %d exited with error code %d.\n", pid, status);
	}
    return 0;
}
