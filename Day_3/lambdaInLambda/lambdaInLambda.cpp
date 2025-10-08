//  main.cpp
//  29_SI_Lambdas_fun_in_fun
//
//  Created by Sathya Babu on 29/05/24.
//

#include <iostream>
using namespace std;


auto makeMeAdeveloper(const std::string_view& name) {

    return  [&]() { cout << " I'm a developer now  " << name << endl; };
}

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    std::string name = " Sathya ";

    auto sayName{

        [&]() { cout << "My name is " << name << endl; }
    };
    sayName();

    // Phase II
    auto sayName2{ makeMeAdeveloper("sathya ") };
    sayName2();

    return 0;
}
/*
Hello, World!
My name is  Sathya
  I'm a developer now  sathya
Program ended with exit code: 0
*/