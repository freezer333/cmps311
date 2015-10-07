#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
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

// important - we're passing a pointer.  The parameters
// are passed by copy, not pass by reference, so if
// you want the thread function to use memory created in your
// parent thread (setting the result, for example), you better
// pass a pointer!
void summation(MyThreadParameter * summationParam) {
    for ( int i = 0; i < summationParam->input; i++ ) {
        summationParam->result += i;
        this_thread::sleep_for (chrono::seconds(1));
    }
}

int main () {
    vector<std::thread> threads;
    MyThreadParameter parameters[5];   // remember scope (what happens if declared within for loop)?
    for ( int i = 0; i < 5; i++ ) {
        int inputValue;
        cout << "Enter input " << i << ":  ";
        cin  >> inputValue;
        parameters[i].input = inputValue;
        threads.push_back(std::thread(summation, &(parameters[i])));
    }
    
    for(int i = 0; i < threads.size(); i++ ){
        threads[i].join();
    }
    for ( int i = 0; i < 5; i++ ) {
        cout << "Summation of " << parameters[i].input << " is " << parameters[i].result << endl;
    }
}