

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
/*
	--- Important ----
	Make sure account.txt is present in the 
	working directory, and that it has
	some integer on the first line (i.e. 1000).
	
	--- Procedure ----
	open bank account file for reading 
	read balance from file 
	close bank account file 
	"steal" half of balance and add  to own personal account 
	open bank account file for writing 
	write new, lower balance to file 
	close bank account file 
	
	--- Expected Results ----
	You'll see that the total amount stolen is 
	normally over 1000, by a lot...
*/


void * theif (void * param) {
	int balance;
	int stolen = 0;
		
	while ( 1 ) 
	{
		// STEP 1, Open the account file and read its contents
		FILE * file = fopen ("account.txt", "r");
		fscanf ( file, "%d", &balance);
		fclose(file);
	
		if ( balance == 0 ) {
			printf("Theif stole total of %d\n",  stolen);
			pthread_exit(0); 
		}
		// STEP 2, Steal half the balance
		if ( balance > 2 ) {
			stolen += balance / 2;
			balance -= balance / 2;
			
		}
		else {
			stolen += 1;
			balance = 0;
		}
		
		// STEP 3, Update the account file
		file = fopen ("account.txt", "w");
		fprintf(file, "%d", balance);
		fclose(file);
	}
}

int main() {
	pthread_t tid1, tid2, tid3, tid4;		// thread identifier 
	pthread_attr_t attr;// thread attributes (will be filled in by OS)
	
	/*  default attributes */
	pthread_attr_init(&attr);
	
	// create the thread
	pthread_create(&tid1, &attr, theif, NULL);
	pthread_create(&tid2, &attr, theif, NULL);
	pthread_create(&tid3, &attr, theif, NULL);
	pthread_create(&tid4, &attr, theif, NULL);
	
	pthread_join ( tid1, NULL);
	pthread_join ( tid2, NULL);
	pthread_join ( tid3, NULL);
	pthread_join ( tid4, NULL);
	
	/// reset the text file so we can run this again right away.
	FILE * file = fopen ("account.txt", "w");
	fprintf(file, "1000");
	fclose(file);
	
}
