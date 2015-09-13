#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define READ_END 0
#define WRITE_END 1

int main () {

  int pfd[2];   // file descriptor for the pipes
  int pid;		
  char buffer[256];		// Used by the parent to store string typed by user.
  char arg[50];			// buffer to write pipe fd into for execlp

  /*  create read/write pipe */
  if ( pipe(pfd) != 0 ) {
    fprintf(stderr, "Pipe could not be created.  Errno:   %i\n", errno);
    exit(0);
  }
  buffer[0] = '\0';
  
  pid = fork();
  if (pid == 0) {
    /*  child process */
	sprintf(arg, "%d", pfd[READ_END]);
	execlp("./echoline", "echoline" , arg, NULL);
  }
  else {
    /*  parent process */
	printf("Type Something:  ");
      
    while (strcmp(buffer, "quit")) {
	 fgets(buffer, 256, stdin);
      buffer[strlen(buffer)-1] = '\0';  // TRIM new line character
      write (pfd[WRITE_END], buffer, strlen(buffer)+1);
    }
	
    wait(NULL);   // wait for the child to complete
    close(pfd[WRITE_END]);
    printf("Parent Exiting\n");
  }
  
  // How many processes will get here (only the parent - the child called execlp - no longer runs this code
  exit(1);
}
