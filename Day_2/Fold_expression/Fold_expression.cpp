//
//  main.cpp
//  28_SI_foldExpressions
//
//  Created by Sathya Babu on 28/05/24.
//

#include <iostream>
using namespace std;

template< typename ... T >
auto doSomeStuff(T... t) {
    return (t + ...);
}

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << doSomeStuff( 8, 9, 10) << endl;
    return 0;
}
// 55.32