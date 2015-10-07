#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

void theif (mutex * m) {
    int balance;
    int stolen = 0;
    while ( 1 ) 
    {
        m->lock();
        // critical section
        ifstream fin("account.txt");
        fin >> balance;
        fin.close();
    
        if ( balance == 0 ) {
            printf("Theif stole total of %d\n",  stolen);
            m->unlock();
            return;
        }
    
        if ( balance > 1 ) {
            stolen += balance / 2;
            balance -= balance / 2;
            
        }
        else {
            stolen += 1;
            balance = 0;
        }
        
        ofstream fout("account.txt");
        fout << balance << endl;
        fout.close();
        
        /* RELEASE LOCK */
        m->unlock();
        
        this_thread::sleep_for (chrono::milliseconds(rand() %1000));
    }
}

int main() {
    
    srand (time(0));
    
    vector<std::thread> threads;

    mutex shared_mutex;;

    for (int i = 0; i < 4; i++ ) {
        threads.push_back(std::thread(theif, &shared_mutex));
    }
    
    for_each(threads.begin(), threads.end(), [](thread & t) { t.join(); });
    
    ofstream fout("account.txt");
    fout << "1000" << endl;
    fout.close();
}