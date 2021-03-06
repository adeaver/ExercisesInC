#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>

#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>
#include <stdlib.h>
// I have no idea what the values for these
// are supposed to be, but for the sake of learning
// I don't think they're really that important

#define ICMP_TIME_EXCEEDED 100
#define ICMP_DEST_UNREACH 100
#define ICMP_EXC_TTL 100
#define ICMP_PORT_UNREACH 100

typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;


/* the following are a few definitions from Stevens' unp.h */

#define max(a,b) ((a) > (b) ? (a) : (b))

/* the following are prototypes for the Stevens utilities in util.c */

void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
	    const struct sockaddr *sa, socklen_t salen);

void loop_ttl ();


/* variables we might want to configure */
extern int max_ttl;
extern int datalen; 

