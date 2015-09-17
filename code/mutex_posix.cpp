

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
/*
open bank account file for reading 
read balance from file 
close bank account file 
"steal" half of balance and add  to own personal account 
open bank account file for writing 
write new, lower balance to file 
close bank account file 
*/

pthread_mutex_t mutex;

void * theif (void * param) {
	int balance;
	int stolen = 0;
		
	while ( 1 ) 
	{
		/* ACQUIRE LOCK  */
		pthread_mutex_lock(&mutex);
		
		
		// critical section
		FILE * file = fopen ("account.txt", "r");
	
		fscanf ( file, "%d", &balance);
	
		fclose(file);
	
		if ( balance == 0 ) {
			printf("Theif stole total of %d\n",  stolen);
			pthread_mutex_unlock(&mutex);
			pthread_exit(0); 
		}
	
		if ( balance > 1 ) {
			stolen += balance / 2;
			balance -= balance / 2;
			
		}
		else {
			stolen += 1;
			balance = 0;
		}
		
		file = fopen ("account.txt", "w");
		fprintf(file, "%d", balance);
		fclose(file);
		
		/* RELEASE LOCK */
		pthread_mutex_unlock(&mutex);
		
		sleep (rand() % 5);
	}
}

int main() {
	pthread_t tid1, tid2, tid3, tid4;		// thread identifier 
	pthread_attr_t attr;// thread attributes (will be filled in by OS)
	
	
	srand (getpid());
	
	/*  default attributes */
	pthread_attr_init(&attr);
	
	/***  CREATE MUTEX ***/
	pthread_mutex_init(&mutex, NULL);
	
	// create the thread
	pthread_create(&tid1, &attr, theif, NULL);
	pthread_create(&tid2, &attr, theif, NULL);
	pthread_create(&tid3, &attr, theif, NULL);
	pthread_create(&tid4, &attr, theif, NULL);
	
	pthread_join ( tid1, NULL);
	pthread_join ( tid2, NULL);
	pthread_join ( tid3, NULL);
	pthread_join ( tid4, NULL);
	
	FILE * file = fopen ("account.txt", "w");
	fprintf(file, "1000");
	fclose(file);
	
}