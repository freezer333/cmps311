#include <iostream>
#include <windows.h>

using namespace std;

class MyThreadParameter {
public:
	MyThreadParameter() {
		this->input =  0;
		this->result = 0;
	}

	int input;
	int result;
};


DWORD WINAPI summation(LPVOID param) {
	MyThreadParameter * summationParam = (MyThreadParameter *) param;
	for ( int i = 0; i < summationParam->input; i++ ) {
		summationParam->result += i;
		Sleep(500);  // Just to simulate that something more substantial is going on.
	}
	return 0;
}

int main () {
	HANDLE workers[5];
	MyThreadParameter parameters[5];   // remember scope (what happens if declared within for loop)?
	for ( int i = 0; i < 5; i++ ) {
		int inputValue;
		cout << "Enter input " << i << ":  ";
		cin  >> inputValue;
		parameters[i].input = inputValue;
		workers[i] = CreateThread(
								   NULL, 
								   0, 
								   summation,
								   &(parameters[i]), 
								   0, 
								   NULL);
		
		if ( workers[i] == NULL ) {
			cerr << "Thread unable to be created." << endl;
			exit (0);
		}
	}
	
	WaitForMultipleObjects(5, workers, TRUE, INFINITE);
	for ( int i = 0 ; i < 5; i++ ) {
		CloseHandle(workers[i]);
		cout << "Summation of " << parameters[i].input << ":  " << parameters[i].result << endl;
	}
	
	system("pause");
}