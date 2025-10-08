//
//  main.cpp
//  29_SI_Lambdas
//
//  Created by Sathya Babu on 29/05/24.
//
/*
Agenda for the day

Forward..
union - Variant
observer

lambda - various codes - Forward..
???
lambda recursion
tuple
Singleton - legacy way.. with shared_ptr
enabling shared ptr from this..
implementng Observer with a usecase
any
optional
*/
#include <iostream>
using namespace std;

class Anonymous {
public:

    template< class T1, class T2 >
    constexpr  auto operator()(T1 a, T2 b)
    {
        return  a + b;
    }

};

//lambda
constexpr auto Sum = [](const auto& a, const auto& b) { return a + b; };

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Function objects vs lambda !\n";
    Anonymous an;
    auto res = an(10, 20);
    cout << res << endl;
    cout << " LAmbda sum = " << Sum(12, 23) << endl;

    // Phase II  lambda as a nameless function

    [] { cout << "excuted a lambda in a raw way!!!"; }();
    ;

    using fun_ptr = int (*)();
    fun_ptr f = []  -> int {  cout << "excuted a lambda yet another way!!!"; return 123; };
    f();



    return 0;
}/*
  Function objects vs lambda !
  30
   LAmbda sum = 35
  Program ended with exit code: 0
  */