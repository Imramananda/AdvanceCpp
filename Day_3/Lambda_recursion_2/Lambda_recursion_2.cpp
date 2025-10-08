//
//  main.cpp
//  29_SI_Lambdas_recursion_2
//
//  Created by Sathya Babu on 29/05/24.
//
//
//  main.cpp
//  29_SI_Lambdas_recursion_1
//
//  Created by Sathya Babu on 29/05/24.
//

#include <variant>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

using var_t = std::variant<int, const char*>;

/*
struct Print{
    void operator() ( int i ){
        cout << i << endl ;
    }
    void operator() ( std::string_view str){
        cout << str << endl ;
    }
};
*/

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

struct Print : PrintInt, PrintString {

    using PrintInt::operator();
    using PrintString::operator();
};


int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "lambda recursion..\n";

    std::vector< var_t > vars = { 1, 2, "Hello, World!" };

    // Print print ;

    for (auto& v : vars) {
        std::visit(Print{}, v);
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