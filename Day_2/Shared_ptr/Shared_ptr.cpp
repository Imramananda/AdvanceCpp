//
//  main.cpp
//  28_SI_Shared_ptr
//
//  Created by Sathya Babu on 28/05/24.
//

#include <iostream>
#include <memory>
using namespace std;

class A {
public:

    void show() {
        cout << " A:: show() " << endl;

    }
    // Phase II

    A(int val) : value(val) {
        std::cout << "Constructing MyClass with value: " << value << std::endl;
    }

    A() {
        cout << " calling constructor " << endl;
    }
    ~A() {
        cout << " calling destructor  are not a true garbage collection  carefully delt memory " << endl;
    }


    void printValue() {
        std::cout << "Value: " << value << std::endl;
    }

private:

    int value;

};
int main() {

    shared_ptr< A >p1(new A);
    cout << p1.get() << endl;
    p1->show();

    shared_ptr< A >p2(p1);

    cout << " p1 : Address   " << p1.get() << endl;  //  Address
    cout << " p2 : Address  " << p2.get() << endl;   //  Address

    // Returns the number of shared_ptr objects
        // referring to the same managed object.
    cout << " p1 : Returns the number of shared_ptr objects " << p1.use_count() << endl; // 2
    cout << " p2 : Returns the number of shared_ptr objects " << p2.use_count() << endl;  // 2

    p1.reset();
    cout << " p2 : Returns the number of shared_ptr objects " << p2.use_count() << endl;  //
    cout << " p1 : Address   " << p1.get() << endl;  //  Address  p1 : Address   0x0
    cout << " p2 : Address  " << p2.get() << endl;   //  Address

    //                              new A( 123 ); elemenated...
    shared_ptr< A > ptr1 = std::make_shared< A >(123);
    shared_ptr< A > ptr2 = ptr1;




    ptr1->printValue();
    ptr2->printValue();
    cout << " p1 : Address   " << ptr1.get() << endl;  //  Address
    cout << " p2 : Address  " << ptr2.get() << endl;   //  Address

}