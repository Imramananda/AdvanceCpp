//
//  main.cpp
//  30_SI_Initilizer_list
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include<vector>
using namespace std;

class MyNumber {

public:

    MyNumber(const std::initializer_list< int >& v) {

        myVec.insert(myVec.end(), v.begin(), v.end());
    }

    MyNumber(int a, int b) {
        cout << " Normal constructor " << a << " " << b << endl;

    }
    MyNumber(int a, int b, int c) {
        cout << " Normal constructor " << a << " " << b << " " << c << endl;

    }
    void print() {
        for (auto itm : myVec) {
            cout << itm << " ";

        }
    }

private:

    std::vector< int > myVec;
};

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    //   depricated way of coding..


    MyNumber myNum(10, 20);
    myNum.print();


    // var number of arguments..
    MyNumber myInit_list_Num{ 12,13,14,15,16,16,17,18,19,20,21 };
    myInit_list_Num.print();

    MyNumber myNum2{ 1,2,3,4,5 };
    myNum2.print();

    return 0;
}
has context menu