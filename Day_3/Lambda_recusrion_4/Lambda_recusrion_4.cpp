//
//  main.cpp
//  29_SI_Lambdas_recursion_4
//
//  Created by Sathya Babu on 29/05/24.
//

#include <variant>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

using var_t = std::variant<int, const char*>;


// Function objects are also called as lambda...
/*
struct PrintInt{
    void operator() ( int i ){
        cout << i << endl ;
    }
};
struct PrintString{
    void operator() ( std::string_view str){
        cout << str << endl ;
    }
};

*/



//< PrintString,PrintInt >
template< class... Ts>
struct Print : Ts... {
    using Ts::operator()...;  // getting fired...   firing point..

};


int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "lambda recursion..\n";

    std::vector< var_t > vars = { 1, 2, "Hello, World!" };

    auto PrintInt = [](int i) { cout << i << endl; };
    auto PrintString = [](std::string_view str) { cout << str << endl; };

    // Print print ;

    for (auto& v : vars) {
        std::visit(
            Print< decltype(PrintString), decltype(PrintInt)>{ PrintString, PrintInt },
            v);
    }

    return 0;
}
/*
lambda recursion..
1
2
Hello, World!
Program ended with exit code: 0
*/