//
//  main.cpp
//  SI_Functional_Composition
//
//  Created by Sathya Babu on 27/05/24.
//
/*
	auto
	decltype
	trialing retur type
	function pointers vs  std::Function
	templates
	call back -> parallel execution..


	vector
	begin , end
	ranges
	iterator..


*/
#include <iostream>
#include<string>
#include<functional>
#include <string_view>


using namespace std;
// shall be covered latter..
std::string_view msg = "hello there";  // &

//auto var  = 100 ;
const  std::string  message = "I'm here ";

// better way
// const std::string_view foo()

const std::string& foo()
{
	return message;
}

//auto& increment( int& a )  { a++ ; return a; }
decltype(auto) increment(int& a) { a++; return a; }

struct A { double x; };
const A* a;


int i;

decltype(a->x) y;
decltype(a->x) z = y;

// C Convention and PASCAL convention

// PASCAL convention  L -> R
//float f( float x ){ return  x + 23.3; }

// Trailing return type
constexpr auto f(const float x) -> float
{
	return  x + 23.3;
}

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

// lets implement the call back...
int resultOfCalc(int (*OP)(int, int),
	int x, int y)
{

	return (*OP)(x, y);
}

template< typename  FN, typename  T1, typename T2>
auto resultOfCalc_2(const FN& op,
	const T1& x,
	const T2& y) -> decltype(op(x, y))
{

	return op(x, y);
}


int main(int argc, const char* argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n" << endl;
	int xyz = 1;
	int one{ 1 };
	const auto f1 = foo();

	decltype(foo()) f2 = foo();
	decltype(auto) f3 = foo();

	cout << f1 <<"F1" << endl;
	cout << f2 <<"F2" << endl;
	cout << f3 <<"F3" << endl;

	int x = 100;
	int& y = increment(x);
	cout << " x " << x << endl;
	cout << " y " << y << endl;


	cout << f(100)<<endl;

	// functional composition..calling a func from a function( Is that a callback ANS : YES )
	// (*myFNPTR)(int,int)

	cout << " Functional composition : " << resultOfCalc(add, 123, 200) << endl;

	int yy = 23;
	// throws error.. to deal with such problems we have to bring in type triats..
    //cout <<" Functional composition 2 add   : " << resultOfCalc_2( add,400,&yy ) << endl ;
	cout << " Functional composition 3 mul : " << resultOfCalc_2(mull, 400, 20) << endl;

	// std::bind  std::apply   std::invoke

	using namespace std::placeholders;

	//    auto std_fun = std::bind(&add, 123, _1 );
	std::function< int(int) > std_fun = std::bind(&add, 123, _1);

	int summ = std_fun(12);
	cout << " binding result " << summ << endl;



	return 0;
}
/*
Hello, World!

I'm here
I'm here
I'm here
  x 101
  y 101
123.3 Functional composition : 323
  Functional composition 3 mul : 8000
  binding result 135
Program ended with exit code: 0
*/