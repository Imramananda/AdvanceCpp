//
//  main.cpp
//  29_SI_Lambdas_mutable
//
//  Created by Sathya Babu on 29/05/24.
//

#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";


    int ammo{ 10 }; int age{ 23 };

    auto shoot{

        [ammo ,age]() mutable {

            --ammo;

            cout << " Pew! " << ammo << " shot's left. " << age << endl;
        }



    };
    shoot();
    shoot();

    return 0;
}