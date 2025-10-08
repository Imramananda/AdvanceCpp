//
//  main.cpp
//  29_SI_tuple
//
//  Created by Sathya Babu on 28/05/24.
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

void funda(int&& aVar) {
    cout << " R - Value over load called " << aVar << endl;
}

void funda(int& aVar) {
    cout << " L - Value over load called " << aVar << endl;
}



void funda(std::string&& aVar) {
    cout << " R - Value over load called str  " << aVar << endl;
}

void funda(std::string& aVar) {
    cout << " L - Value over load called str  " << aVar << endl;
}

//
//template<typename  T >
//T&& my_Forward( typename std::remove_reference_t< T >::type& param)
//{
//    return static_cast<T&&>( param);
//}

template<typename  T >
void call_funda(T&& parg) {   // Argument universal reference..

    //  funda( std::move( parg ));
      //  funda(my_Forward< T >( parg ) );
    funda(std::forward<T>(parg));

}


void myStr(std::string& str) {}

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "perfect forwarding...!\n";

    int myVar = 5;  // lvalue

    call_funda(myVar);   // lValue
    call_funda(12);      // rValue

    std::string str = " HEllo there "; // lValue
    call_funda(str);   // lValue
    call_funda("Hello rValue ");   // lValue

    // An example
   // myStr( " HEllo ");  // rValue

   // std::string str = " HEllo there "; // lValue
  //  myStr( str );

    return 0;
}