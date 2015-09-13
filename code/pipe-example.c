
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define READ_END 0
#define WRITE_END 1

int pfd[2];

int main() {

	int pid;
	int retval;
	int testVariable;
	
	testVariable = 10;
	
	retval = pipe (pfd);
	
	if (retval != 0 ) {
		fprintf(stderr, "Pipe failed\n");
		exit(0);
	}
	
	pid = fork();
	
	if ( pid == 0 ) {
		
		/* write a variable to the pipe */
		printf("Child:  %d\n", testVariable);
		testVariable = 5;
		
		write (pfd[WRITE_END], &testVariable, sizeof(int));
	}
	else {
		
		printf("Parent:  %d\n", testVariable);

		/* read a variable from the pipe */
		read (pfd[READ_END], &testVariable, sizeof(int));
		printf("Parent after read:  %d\n", testVariable);
		wait(NULL);
	}
		
	exit(0);

}