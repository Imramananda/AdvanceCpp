//
//  main.cpp
//  30_SI_StructuralBinding_array
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include<map>
using namespace std;

struct Point {
    int x;
    int y;
};
// phase II

struct MyStruct {
    int i = 0;
    std::string s;
};
MyStruct ms;

// phase III

MyStruct getStruct() {
    return MyStruct{ 42, "hello" };
}



int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    // Point  p(12,22);

    Point  p{ 12,34 };

    Point pp{ .x = 12,.y = 20 };

    auto [a, b] = p;
    cout << a << b << endl;

    ms.i = 10;
    ms.s = "Sathya";

    auto [v, s] = ms;
    auto [u1, v1] = getStruct();
    cout << u1 << " : " << v1 << endl;

    std::map<int, std::string> myMap;
    myMap.insert({ 1, "one" });
    myMap.insert({ 2, "two" });
    myMap.insert({ 3, "three" });

    for (const auto& pair : myMap) {
        int key = pair.first;
        std::string value = pair.second;

        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }

    // MOdern c++
    for (const auto& [key, value] : myMap) {
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }

    MyStruct ms{ 34,"Sathya" };
    auto [age, name] = ms;

    return 0;
}
has context menu