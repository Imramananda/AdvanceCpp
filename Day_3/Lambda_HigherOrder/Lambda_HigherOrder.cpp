//
//  main.cpp
//  29_SI_Lambdas_HIgherOrder
//
//  Created by Sathya Babu on 29/05/24.
//

#include<iostream>

const auto less_than = [](auto x) {  // x : 5


    // y 22
    return [x](auto y) { std::cout << " y " << y << " x " << x << std::endl;

    return y < x;   // comp  y with the ref x now

        };

    };

int main(void)

{

    auto less_than_five = less_than(5);

    std::cout << " TRUE " << less_than_five(22);
    std::cout << less_than_five(3) << std::endl;

    std::cout << less_than_five(10) << std::endl;

    return 0;

}
/*
TRUE  y 22 x 5
0 y 3 x 5
1
y 10 x 5
0
Program ended with exit code: 0
*/
has context menu