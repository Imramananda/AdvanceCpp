//
//  main.cpp
//  29_SI_union_variant
//
//  Created by Sathya Babu on 29/05/24.
//

#include <iostream>
#include <variant>
using namespace std;

union Value {
    int i;
    double d;
};



int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    Value v;
    v.d = 76.1234;
    cout << v.d << endl;
    cout << v.i << endl;  // bad access...

    // Variant..

    std::variant< int, float > vv(99);
    cout << " Access by index 0  " << (get< 0 >(vv)) << endl;
    cout << " Access by type  0 " << (get< int  >(vv)) << endl;

    std::variant<int, std::string> var5{ 120 }, var6{ "hi" };

    std::cout << "  var 5 int   " << std::get<0>(var5) << '\n';  //  var 5 int   120
    std::cout << "  var 6 data  " << std::get<1>(var6) << '\n';  //  var 6 data  hi
    std::cout << "  var 5 index " << var5.index() << '\n';       // var 5 index 0
    std::cout << "  var 6 index " << var6.index() << '\n';       // var 6 index 1
    std::cout << "  fetch data from Union  0 " << std::get<0>(var5);   // fetch data from Union  0 120

    using  variant = std::variant<int, std::string>;
    variant var;
    var = "Sathya";
    std::cout << std::endl << " var name " << std::get<1>(var) << " index "
        << var.index() << endl; // var name Sathya index 1

    var = 110;
    std::cout << std::endl << " var num " << std::get<0>(var) << " index "
        << var.index() << endl; // var num 110 index 0


    return 0;


}