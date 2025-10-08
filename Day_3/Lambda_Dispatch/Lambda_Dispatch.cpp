//
//  main.cpp
//  29_SI_Lambdas_Dispatch
//
//  Created by Sathya Babu on 29/05/24.
//
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
void setValue(const int& val) {} // this is declared as lvalue
int main() {

    int h = 23;
    setValue(h);
    setValue(23);
    std::cout << std::endl;



    // dispatch table
    std::map< const char, std::function<double(double, double)> > dispTable{
        // std::map< const char , double (*function_type)(double,double)> dispTable{ // error
         {'+',[](double a, double b) { return a + b; } },
         {'-',[](double a, double b) { return a - b; } },
         {'*',[](double a, double b) { return a * b; } },
         {'/',[](double a, double b) { return a / b; } } };

    // do the math
    std::cout << "3.5+4.5= " << dispTable['+'](3.5, 4.5) << std::endl;
    std::cout << "3.5-4.5= " << dispTable['-'](3.5, 4.5) << std::endl;
    std::cout << "3.5*4.5= " << dispTable['*'](3.5, 4.5) << std::endl;
    std::cout << "3.5/4.5= " << dispTable['/'](3.5, 4.5) << std::endl;

    // add a new operation
    dispTable['^'] = [](double a, double b) { return std::pow(a, b); };
    std::cout << "3.5^4.5= " << dispTable['^'](3.5, 4.5) << std::endl;

    std::cout << std::endl;

};
/*
3.5+4.5= 8
3.5-4.5= -1
3.5*4.5= 15.75
3.5/4.5= 0.777778
3.5^4.5= 280.741

Program ended with exit code: 0
*/
has context menu


has context menu