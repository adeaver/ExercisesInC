/* Example code for Software Systems at Olin College.

Copyright 2012 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdlib.h>
#include <pthread.h>
#include "mutex.h"

Mutex *make_mutex()
{
    Mutex *mutex = (Mutex *) malloc(sizeof(Mutex));
    pthread_mutex_init(mutex->mutex, NULL);
    return mutex;
}

int mutex_lock(Mutex *mutex)
{
    return pthread_mutex_lock(mutex->mutex);
}

int mutex_unlock(Mutex *mutex)
{
   return pthread_mutex_unlock(mutex->mutex);
}
