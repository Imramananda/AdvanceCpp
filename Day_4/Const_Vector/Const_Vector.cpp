//
//  main.cpp
//  30_SI_ConstVector
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include <vector>

int main() {
	const int a = std::vector<int>{ 1, 2, 3 }.size();      // vectors are const by default
	constexpr int b = std::vector<int>{ 1, 2, 3 }.size();  // ompile-time error

	std::cout << a << std::endl;
	std::cout << b << std::endl;
}