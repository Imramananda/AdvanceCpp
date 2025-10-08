//
//  main.cpp
//  29_SI_Lambdas_ArrySortLambda
//
//  Created by Sathya Babu on 29/05/24.
//


#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <string_view>
using namespace std;

int main()
{
    std::array<int, 10> s = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

    auto print = [&s](std::string_view const rem) {
        for (auto a : s) {
            cout << a << " ";
        }
        cout << " : " << rem << endl;

        };

    std::sort(s.begin(), s.end());
    print(" Sorted with the default operator");

    std::sort(s.begin(), s.end(), std::greater< int >());
    print(" Sorted with the std lib compare fun object");

    struct {
        bool operator() (int a, int b) const { return a < b; }
    } customLess;


    std::sort(s.begin(), s.end(), customLess);
    print(" Sorted with the std lib compare fun object");

    std::sort(s.begin(), s.end(), [](int a, int b) {
        return a > b;
        });
    print("sorted with a lambda expression");


    return 0;
}
/*
0 1 2 3 4 5 6 7 8 9  :  Sorted with the default operator
9 8 7 6 5 4 3 2 1 0  :  Sorted with the std lib compare fun object
0 1 2 3 4 5 6 7 8 9  :  Sorted with the std lib compare fun object
9 8 7 6 5 4 3 2 1 0  : sorted with a lambda expression
Program ended with exit code: 0
*/