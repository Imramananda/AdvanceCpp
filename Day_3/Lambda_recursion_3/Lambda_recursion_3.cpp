//
//  main.cpp
//  29_SI_Lambdas_recursion_3
//
//  Created by Sathya Babu on 29/05/24.
//
//

#include <variant>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

using var_t = std::variant<int, const char*>;



struct PrintInt {
    void operator() (int i) {
        cout << i << endl;
    }
};
struct PrintString {
    void operator() (std::string_view str) {
        cout << str << endl;
    }
};
/*
struct Print : PrintInt, PrintString {

    using PrintInt::operator();
    using PrintString::operator();
};
*/

template< class... Ts>
struct Print : Ts... {
    using Ts::operator()...;

};


int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "lambda recursion..\n";

    std::vector< var_t > vars = { 1, 2, "Hello, World!" };

    // Print print ;

    for (auto& v : vars) {
        std::visit(Print<PrintInt, PrintString>{}, v);
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