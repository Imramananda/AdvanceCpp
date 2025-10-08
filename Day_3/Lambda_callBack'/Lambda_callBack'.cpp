//
//  main.cpp
//  29_SI_Lambdas_CallBack
//
//  Created by Sathya Babu on 29/05/24.
//


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// receive lambda as funPtr(int ) = (int){ prints the value }

void ForEach(const std::vector< int >& values, void(*funPtr)(int)) {

    for (int value : values)
    {
        cout << " about to call lambda {}" << endl;
        funPtr(value);    // its a call back {}
    }
}


int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    std::vector< int > values = { 1,2,3,4,5 };
    // FROM LAMBDA WE RECEIVE THE VALUE VIA -> funPtr( value );
    ForEach(values, [](int value) { cout << " Value : " << value << endl; });
    return 0;
}

/*
Hello, World!
  about to call lambda {}
  Value : 1
  about to call lambda {}
  Value : 2
  about to call lambda {}
  Value : 3
  about to call lambda {}
  Value : 4
  about to call lambda {}
  Value : 5
Program ended with exit code: 0
*/
has context menu