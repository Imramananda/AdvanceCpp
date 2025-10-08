//
//  main.cpp
//  29_SI_Lambdas_Aggregate
//
//  Created by Sathya Babu on 29/05/24.
//
#include <functional>
#include <iostream>

int myAge = 34;

struct Baz {

    std::function< void()> foo() {

        return [&] { std::cout << s << age << std::endl; };
    }

    std::string s;
    int age;
};



int main() {
    auto f1 = Baz{ "abc",23 }.foo();  // while Aggregate  constructor is not required..
    auto f2 = Baz{ "xyz" ,34 }.foo();
    f1();
    f2();
}