//
//  main.cpp
//  30_SI_Future_promise
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include <future>
using namespace std;


void ThreadFun(promise< int >& prom) {


    this_thread::sleep_for(chrono::seconds(3)); // block for 3 sec
    // we are receving it from a server
    // info stcok..
    prom.set_value(393);

}
int main(int argc, const char* argv[]) {
    // insert code here...
    promise<int> myPromise;
    future<int> fut = myPromise.get_future();

    cout << " At main " << endl;
    thread t1{ ThreadFun, ref(myPromise) };


    cout << " Main thread --> " << fut.get() << endl;  //  // Blocks the line till it receives the data
    t1.join();   // try by putting this line in a remark still it works throws an error


    cout << " End of my code " << endl;
    return 0;
}
has context menu