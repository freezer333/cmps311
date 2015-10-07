#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
#include <time.h>

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


void * summation(void * param) {
	MyThreadParameter * summationParam = (MyThreadParameter *) param;
	for ( int i = 0; i < summationParam->input; i++ ) {
		summationParam->result += i;
		sleep(5);  // Just to simulate that something more substantial is going on.
	}
	pthread_exit(0); 
}

static double TimeSpecToSeconds(struct timespec* ts)
{
    return (double)ts->tv_sec + (double)ts->tv_nsec / 1000000000.0;
}

int main () {
	pthread_t workers[5];		// thread identifier 
	pthread_attr_t attr[5]; // thread attributes (will be filled in by OS)
	int total_serial_sleep_time = 0;
	struct timespec start;
    struct timespec end;


	MyThreadParameter parameters[5];   // remember scope (what happens if declared within for loop)?
	for ( int i = 0; i < 5; i++ ) {
		int inputValue;
		cout << "Enter input " << i << ":  ";
		cin  >> inputValue;
		parameters[i].input = inputValue;
		total_serial_sleep_time += (inputValue * 5);
	}

	clock_gettime(CLOCK_MONOTONIC, &start);

	for ( int i = 0; i < 5; i++) {

		pthread_attr_init(&(attr[i]));
		pthread_create(&(workers[i]), &(attr[i]), summation,  &(parameters[i]) );
		
		if ( workers[i] == 0 ) {
			cerr << "Thread unable to be created." << endl;
			exit (0);
		}
	}
	
	for ( int i = 0; i < 5; i++ ) {
		pthread_join ( workers[i], NULL);
	}

	clock_gettime(CLOCK_MONOTONIC, &end);
	cout << "Serial sleep time:  " << total_serial_sleep_time << endl;
	cout << "Actual Sleep took:  " <<  TimeSpecToSeconds(&end) - TimeSpecToSeconds(&start) << " seconds" << endl;
	for ( int i = 0 ; i < 5; i++ ) {
		cout << "Summation of " << parameters[i].input << ":  " << parameters[i].result << endl;
	}
	
	
}