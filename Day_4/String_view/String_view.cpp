[4:13 PM] P.Sathya(Unverified)
//
//  main.cpp
//  30_SI_string_View
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include <string_view>

int main() {
    const char* cstr = "Hello, World!";
    std::string_view view(cstr, 5);  // View the first 5 characters
    //  view[0] = 'X';  // Error: std::string_view is read-only
    std::cout << view << std::endl;  // Outputs: Hello
    return 0;
}