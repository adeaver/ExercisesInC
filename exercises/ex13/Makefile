CC = gcc
CFLAGS = -g -Wall
GLIB_FLAGS = -I/usr/local/Cellar/glib/2.56.0/include/glib-2.0 -I/usr/local/Cellar/glib/2.56.0/lib/glib-2.0/include -I/usr/local/opt/gettext/include -I/usr/local/Cellar/pcre/8.42/include -L/usr/local/Cellar/glib/2.56.0/lib -L/usr/local/opt/gettext/lib -lglib-2.0 -lintl -Wl,-framework -Wl,CoreFoundation
LIBS = -lglib-2.0

list_errors: list_errors.c
	$(CC) -o $@ $^ $(CFLAGS)

word_count: word_count.c
	$(CC) -o $@ $^ $(CFLAGS) $(GLIB_FLAGS) $(LIBS)
