#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#include "ThreadingPkgInternal.h"
 
int print_message_function(void *ptr);
 
/* struct to hold data to be passed to a thread
this shows how multiple data items can be passed to a thread */
typedef struct str_thdata
{
    int thread_no;
    char message[100];
} thdata;

namespace toyproj {
	namespace threadingpkg{
		void DummyThreadingFunc() {
		    pthread_t thread1, thread2;
		    thdata data1, data2;
		 
		    data1.thread_no = 1;
		    strcpy(data1.message, "Hello!");
		 
		    data2.thread_no = 2;
		    strcpy(data2.message, "Hi!");
		 
		    pthread_create (&thread1, NULL, (void* (*)(void*)) &print_message_function, (void *) &data1);
		    pthread_create (&thread2, NULL, (void* (*)(void*)) &print_message_function, (void *) &data2);
		 
		    pthread_join(thread1, NULL);
		    pthread_join(thread2, NULL);
		}
	}
}
 
int print_message_function ( void *ptr )
{
    thdata *data;
    data = (thdata *) ptr;  /* type cast to a pointer to thdata */
 
    /* do the work */
    printf("Thread %d says: %s\n", data->thread_no, data->message);
 
    return 0;
}

