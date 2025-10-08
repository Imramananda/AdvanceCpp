//
//  main.cpp
//  SI_ComposeRequires_1
//
//  Created by Sathya Babu on 27/05/24.
//

#include <iostream>
using namespace std;

// concept MandateWhileDriving = requires(  T t ){
// C++ 20

// typedef C++
// using modern C++

// --------- using  few type triats...    requires


template< typename T>
void foo(T arg) requires std::is_integral_v< T >;

template< typename T>
void bar(T arg) requires (sizeof(T) == 4) { }

template< typename T>
void someFun(T arg) requires (std::is_integral_v< T > && sizeof(T) == 4) { };

template< typename T>
void someFun(T arg) requires (!std::is_pointer_v< T >) {}

//--------------------------------------------------------------------

template< typename T>
concept MandateWhileDriving = requires(T t) {

	{ t.acceleartor() };
	{ t.applyBreak() };
	{ t.fuel };

	// Phase II
		requires std::is_same_v< decltype(t.fuel), float >; // fuel must be of type float
		requires requires(T t) { { t.fuel } -> std::convertible_to<float>; }; // fuel must be convertable to float
	{ t.fuel > 1.0  };
};


// Phase III
template< int fuel>
	requires(fuel >= 10)
float pump(int additionalOil)  requires(fuel >= 10)
{
	int minFuel = 10.0f;
	if (fuel + additionalOil < minFuel) {
		throw std::runtime_error(" CAR would stop any min!!!");
	}
	return fuel + additionalOil;
}

//-------------------------------------------------------------------------------
//template< typename T>
template< MandateWhileDriving T >
void drive(T arg)
{
	cout << " Function drive called with an argument of type T " << typeid(arg).name() << endl;

}

class Car {
public:
	void acceleartor() {
		cout << " Presss the metal... acceleartor" << endl;
	}
	void applyBreak() {
		cout << " Presss the Break" << endl;
	}
	void NotRelatedToDrive() {
		cout << " NotRelatedToDrive " << endl;
	}
	float fuel = 0;
};



int main(int argc, const char* argv[]) {
	// insert code here...
	std::cout << "  Car code \n";
	Car myCar;
	drive(myCar);
	//    myCar.fuel = 0 ;
	myCar.acceleartor();
	myCar.applyBreak();

	// Phase III

	try {
		cout << " Pump : " << pump< 30 >(20) << endl;
	}
	catch (const std::runtime_error& error) {
		cout << " Exception : " << error.what() << endl;
	}
	return 0;
}
/*
Car code
  Function drive called with an argument of type T 3Car
  Presss the metal... acceleartor
  Presss the Break
  Pump : 50
Program ended with exit code: 0
*/