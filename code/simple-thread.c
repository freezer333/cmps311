

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void * threadfunc(void *param); 

int main(int argc, char ** argv) {
	int value = 5; 
	pthread_t tid;		// thread identifier 
	pthread_attr_t attr; // thread attributes (will be filled in by OS)
	
	/*  default attributes */
	pthread_attr_init(&attr);
	
	// create the thread
	
	printf("The original vlaue is %d\n", value);
	
	pthread_create(&tid, &attr, threadfunc, &value);
	
	/*  wait for newly created thread to exit */
	
	pthread_join ( tid, NULL);
	
	printf("The final vlaue is %d\n", value);
}

void * threadfunc(void * param) {
	int * ip = (int *) param;
	(*ip)++;
	pthread_exit(0); // required for proper deallocation of thread.
}
		
