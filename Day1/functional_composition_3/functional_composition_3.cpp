//
//  main.cpp
//  SI_Functional_Composition_3
//
//  Created by Sathya Babu on 27/05/24.
//

#include <iostream>
#include<functional>
using namespace std;

// not implemented.... FYI
template< typename  Fn, typename T>
struct is_invokable_with : std::is_invocable<Fn, T> {};

template<typename T>
struct is_variable : std::is_object< T > {};

constexpr auto add(const int x, const int y) -> int {
	return x + y;
}
constexpr auto mull(const int x, const int y) -> int {
	return x * y;
}

// way of coding ios depricated...
int (*myFNPTR)(int x, int y) = add;
// C++ 11
std::function< int(int, int) > func = add;

template< typename  FN, typename  T1, typename T2>
auto resultOfCalc_2(const FN& op,
	const T1& x,
	const T2& y) -> std::enable_if_t<
	std::is_invocable_v<FN, T1, T2>&&
	is_variable< T1 >::value&&
	is_variable< T2 >::value,
	decltype(op(x, y)) >
{

	return op(x, y);
}


int main(int argc, const char* argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";

	cout << " Functional composition : " << resultOfCalc_2(add, 123, 200) << endl;
	return 0;
}
/*
Hello, World!
  Functional composition : 323
Program ended with exit code: 0
*/