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

struct Print {
    void operator() (int i) {
        cout << i << endl;
    }
    void operator() (std::string_view str) {
        cout << str << endl;
    }
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