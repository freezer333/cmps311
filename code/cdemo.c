
#include <stdio.h>
#include <stdlib.h>

#define FILENAME_PREFIX "employee"

typedef struct Employee {
	char firstName[50];
	char lastName[50];
	int empID;
} Employee;


void printToScreen(Employee *e) {
	printf("%d\n%s %s\n", e->empID, e->firstName, e->lastName);
}

void initialize(Employee * e) {
	e->empID = -1;
	strcpy(e->firstName, "Unknown");
	strcpy(e->lastName, "Unknown");
}



int main() {
	/* in a pure C environment, you must declare variables first */
	struct Employee emp;
	char filename[50];
	FILE * f;
	
	
	initialize(&emp);
	

	printf("Enter ID:  ");
	scanf("%d", &(emp.empID) ); /* & needed because scanf requires a pointer  */
	printf("Enter First name:  ");
	scanf("%s", emp.firstName); /* no & because firstName is a char * already  */
	printf("Enter Last name:  ");
	scanf("%s", emp.lastName); /* no & because last is a char * already */
	
	
	sprintf(filename, "%s%d.txt", FILENAME_PREFIX, emp.empID);
	f = fopen(filename, "w");
	if ( f == NULL ) {
		fprintf(stderr, "Cannot create %s.\n", filename);
		exit(0);
	}
	fprintf(f, "%d\n%s %s\n", emp.empID, emp.firstName, emp.lastName);
	fclose(f);
	
	printToScreen(&emp);
	exit(0);
	
	
	
}