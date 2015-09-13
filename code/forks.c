#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {

	int pid;  // process ID
	int testVariable;
	
	testVariable = 10;
	
	pid = fork();
	
	if ( pid == 0 ) {
		/*  child process */
		printf("Child - Variable = %i\n", testVariable);
		testVariable = -10;
		printf("Child - Changed Variable to %i\n", testVariable);
		sleep(5);
	}
	else {
		/* parent process */
		printf("*** Parent - Variable = %i\n", testVariable);
		printf("*** Parent - Waiting for child to terminate \n");
		wait (NULL);  /* wait for child to finish */
		printf("*** Parent - Child terminated \n");
		printf("*** Parent - Variable = %i\n", testVariable);
	}
	
	// Add a print statement here - what will happen?
	exit (0);


}
