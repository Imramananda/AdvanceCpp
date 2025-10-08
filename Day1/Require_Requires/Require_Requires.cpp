//  SI_requires_requires_1
//

#include <iostream>
#include <vector>
using namespace std;
// Phase II code which smells...
template< typename  T >
void presenceOfNestedType_r_r(T arg)  requires requires { typename T::value_type; }
{
	cout << "function Presence of nested type called with type T r_r  : " << endl;
	for (const auto& elem : arg) {
		cout << elem << " ";
	}
}
// code without a smell..
template< typename  T >
concept HasValueType = requires{ typename T::value_type; };
// requires T to have a nested type value_type

template< typename  T >
void presenceOfNestedType(T arg) requires HasValueType< T > {
	// functional implementation
	cout << "function Presence of nested type called with type T :  "<<typeid(arg).name() << endl;
	// range for loop..

	for (const auto& elem : arg) {
		cout << elem <<"->" << " ";
	}
	cout << endl;
}

int main(int argc, const char* argv[]) {
	// insert code here...
	std::cout << "requires requires \n";
	std::vector< int > vec = { 1,2,3,4,5 };
	presenceOfNestedType(vec);
	//presenceOfNestedType( 34 );
	presenceOfNestedType_r_r(vec);
	return 0;
}
/*
requires requires
function Presence of nested type called with type T :
1 2 3 4 5 function Presence of nested type called with type T r_r  :
1 2 3 4 5 Program ended with exit code: 0
*/