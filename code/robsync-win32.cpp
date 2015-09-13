#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
open bank account file for reading 
read balance from file 
close bank account file 
"steal" half of balance and add  to own personal account 
open bank account file for writing 
write new, lower balance to file 
close bank account file 
*/

HANDLE mutex;

DWORD WINAPI theif (LPVOID param) {
	int balance;
	int stolen = 0;
	while ( 1 ) 
	{
		WaitForSingleObject(mutex, INFINITE);
		// critical section
		FILE * file = fopen ("account.txt", "r");
		fscanf ( file, "%d", &balance);
	
		fclose(file);
	
		if ( balance == 0 ) {
			printf("Theif stole total of %d\n",  stolen);
			ReleaseMutex(mutex);
			return 0;
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
		ReleaseMutex(mutex);
		
		Sleep (rand() % 1000);
	}
}

int main() {
	
	srand (GetTickCount());
	
	HANDLE threads[4];

	mutex = CreateMutex(NULL, FALSE, NULL);

	for (int i = 0; i < 4; i++ ) {
		threads[i] = CreateThread( NULL, 0, theif,NULL, 0, NULL);
	}
	
	WaitForMultipleObjects(4, threads, TRUE, INFINITE);
	
	FILE * file = fopen ("account.txt", "w");
	fprintf(file, "1000");
	fclose(file);
	
}