//
//  main.cpp
//  SI_range_Vector
//
//  Created by Sathya Babu on 27/05/24.
//

#include <iostream>
#include <vector>
#include <ranges>
using namespace std;

template<typename T>
concept range_1 = requires(T & t) {  // t is myRange class

	std::ranges::begin(t);  // lazy 1..
	std::ranges::end(t);

};
template<range_1 R >
void printRange(const R& r)
{
	for (const auto& value : r) {
		cout << " print range : " << value << " ";
	}
	cout << endl;
}


struct MyRange {
	int data[3] = { 11,12,13 };
	auto begin() const { return std::begin(data); }
	auto end()  const { return std::end(data); }
};


auto even(int i) { return i % 2 == 0; }

int main(int argc, const char* argv[]) {
	// insert code here...
	std::cout << "Vector \n";

	MyRange myRange;
	printRange(myRange);
//
	// initilizer_list
	for (auto i : { 10,20,30,40,50 }) {
		cout <<  i << " ";
	}
	cout << endl;

	// lazy range  1 ...
	for (int i : std::ranges::iota_view{ 1, 10 })
	{
		cout <<  i << " ";
	}
	cout<< endl;

	// eager factory.. 1..

	
	for (int i : std::views::iota(1, 10))
	{
		cout << " range : " << i << " ";
	}

	// functional composition  a( b( c ( d() ) ) )
	auto lazyRange = std::ranges::iota_view{ 1, 20 } | std::views::filter(even);
	for (auto i : lazyRange) {
		cout << endl << " Lazy range " << i << endl;
	}

	// functional composition  a( b( c ( d() ) ) )
	auto range = std::views::iota(1, 10) | std::views::filter(even);
	for (auto i : range) {
		cout << endl << " eager range " << i << endl;
	}

	//----------- Known stuff------------------------

	std::vector< int > v{ 1,2,3,4,5 };

	v.push_back(230);
	v.push_back(123);


	v.emplace_back(987);


	for (int i = 0; i <= v.size(); i++)
	{

		cout << "Display vector data " << v[i] << endl;
	}
	

	// ranges::view -> begin() end()
	// lazy operator..
	//   static :: iterator
	for (vector< int > ::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout << "iterator " << *i << endl;
	}

	for (int x : v)
	{
		cout << " range x  " << x << endl;
	}

	for (int& xx : v)
	{
		xx += 5;
		cout << " range x  " << xx << endl;
	}

	cout << " Element at index 0 " << v.at(0) << endl;
	cout << " Element at index 2 " << v.at(2) << endl;
	cout << " Element at index 5 " << v.at(5) << endl;

	v.at(1) = 111;
	v.at(4) = 444;

	for (const int& i : v) {

		cout << i << " ";
	}

	// declare iterator
	vector<int>::iterator iter;

	// use iterator with for loop
	for (iter = v.begin(); iter != v.end(); ++iter) {
		cout << " via iterator " << *iter << "  ";
	}


	return 0;
}