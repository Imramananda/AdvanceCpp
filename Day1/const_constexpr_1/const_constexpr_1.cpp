//
//  main.cpp
//  si_Module_1
//
//  Created by Sathya Babu on 27/05/24.
//
/*

   Agenda for the day..

   what is depricated in C++

   NULL vs nullptr
   if
   for
new - delete
int i vs const constint constval
constexpr
vector - emplace call back , wrappers... * & this..
this -> shared_fromt_his()
this -> proxy..
template... vs type traits
Variadic expressions..
copy copnstructors  - move constructs.. lValue , rValue forward..
Aggregates..
constructor over loads...  vs initilizer list..
fun -> trailing return types with decltype auto
lambdas.. -> call back.. Higher order functions
Functional composition.. Parallel algorithms..
return statements
tuple
void* any
virtual functions -> CRTP / coVariant..

MC++ 98 11 13 14 17 20 23




*/

#include <iostream>
using namespace std;

constexpr auto fun(const int x, const int y)
{
    return x + y;

}
//void foo( const int n ){
//    
//    for( int i = 0 ; i < n ; i++){
//        // loop body( iteration 0 )
//        // loop body( iteration 1 )
//        // loop body( iteration 2 )
//        // loop body( iteration 03)
//    }
//}


const     double PI1 = 3.141592653589793;
constexpr double PI2 = 3.141592653589793;

//constexpr double PI3 = PI1;

constexpr double PI3 = PI2;

const int i = 100;
int arr[i];

class test3
{
public:
    int value;

    constexpr  test3(int Value) :value(Value) {}

    constexpr  int getValue() const
    {
        return  value;
    }

};
constexpr test3 x(100);
int arry[x.getValue()];

// Phase II


//const int i = 100 ;

template< typename T >
constexpr auto  printInfo(const T& t) {

    //    if(  std::is_integral< T >::value )
    if  constexpr (std::is_integral_v< T >) {

        cout << " Is int" << endl;
        return  t + 1;  // int
    }
    else {
        cout << " is  float " << endl;
        return  t + 1.0; // 'auto' in return type deduced as 'double' here but deduced as 'int' in earlier return statement
    }
}


int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    printInfo(15);
    printInfo(152.34);


    //const   int i  = 123 ;

    cout << " fun " << fun(120, 300) << endl;


    return 0;
}