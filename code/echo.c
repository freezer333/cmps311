

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main (int argc, char ** argv) {
	// The first argument is the int identifier of the
	// the pip to read from
	int pfd = atoi(argv[1]);
	char buffer[256];		
	buffer[0] = '\0';
	while (strcmp (buffer, "quit") ) {
		read(pfd, buffer, 256);
		printf("ECHO:  %s\n");
    }
    
    printf("Child Process ending....\n");
    close(pfd);
	exit(1);
}
