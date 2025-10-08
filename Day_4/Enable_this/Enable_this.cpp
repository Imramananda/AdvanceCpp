//
//  main.cpp
//  30_SI_enable_this
//
//  Created by Sathya Babu on 30/05/24.
//
/*

Agenda for the day..
1.  ref_wrappers  -> vectors...
2.  enable_shared_this
3.  Visitor vs visit and variant..
4.  threads...

Study code Visitor with enable_shared_this
Observer with lambdas..
Car application.. having a Async thread in a complicated case..




// Afternoon
     structured array
    Aggregate
tupple  - study app on tupple recursion with variadic expressions..
any
optioonal
inline namespace..


5PM MCQ...
Feed back- COnsolidated..
MCQ..



*/

#include <iostream>
using namespace std;


class MyClass2 {
public:
    void fun() {
        std::cout << "Hello,from Myclas2 !" << std::endl;
    }

};
// Unique  - shared?

//                     // Proxy design pattern
class MyClass : public std::enable_shared_from_this< MyClass > {

public:
    int var = 123;
    MyClass2 myClass2;
    std::shared_ptr<MyClass> getShared() {
        return  shared_from_this();
        // Proxy design pattern
    }
    void print() {
        std::cout << "Hello, I am MyClass!" << std::endl;
    }

};

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::shared_ptr<MyClass> obj = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> sharedObj = obj->getShared();
    obj->myClass2.fun(); // its ok since MyClass2 is an inner class
    obj->var = 567;
    sharedObj->print();

    // phase II

    std::cout << "--> Address using shared_from_this() : " << sharedObj.get() << std::endl;

    // Using this  way is dangerous

    MyClass* rawPtr = obj.get();
    std::cout << "--> Address using this: " << rawPtr << std::endl;
    std::cout << "--> var using this: " << rawPtr->var << std::endl;
    obj->var = 123;
    std::cout << "--> var changed now using this: " << rawPtr->var << std::endl;


    return 0;
}
/*
Hello, World!
Hello,from Myclas2 !
Hello, I am MyClass!
--> Address using shared_from_this() : 0x600001484498
--> Address using this: 0x600001484498
--> var using this: 567
--> var changed now using this: 123
Program ended with exit code: 0
*/