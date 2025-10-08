//
//  main.cpp
//  29_SI_Lambdas_TrailingReturnType
//
//  Created by Sathya Babu on 29/05/24.
//


#include <iostream>
#include <tuple>
using namespace std;



auto testSpeedString = [](int speed) -> std::string {
    if (speed > 110) return "you're a super fast"; else return "you're a regular";
    };

int main() {
    auto str = testSpeedString(190);
    str += " driver"; // works fine
    cout << " returned : " << str << endl;

}