#include <iostream>
#include <vector>
using namespace std;

int main()
{

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