[4:48 PM] P.Sathya(Unverified)
//
//  main.cpp
//  30_SI_Tuppple
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include <tuple>
#include <string>
#include <functional>
#include <vector>

using namespace std;

tuple<int, string, double> f()
{
    int i{ 108 };
    string s{ "Some text" };
    double d{ .01 };

    return { i,s,d };
}
// return type
/*
auto[x, y, z] = f(); // init from tuple
    cout << x << " " << y << " " << z << endl; // 108 Some text 0.01

*/
struct S
{
    string name;
    int num;
};

// return type

S g()
{
    string t{ "hello" };
    int u{ 42 };
    return { t, u };
}


//    My last tuple code.....
auto get_student(int id)
{
    if (id == 0)
        return std::make_tuple(3.8, 'A', "Sharan");
    if (id == 1)
        return std::make_tuple(2.9, 'C', "Sathya");
    if (id == 2)
        return std::make_tuple(1.7, 'D', "Suresh");
    // it is not allowed to return 0 directly
    // return type is std::tuple<double, char, std::string> return std::make_tuple(0.0, 'D', "null");
    return std::make_tuple(0.0, 'D', "null");
}
void myLastTupleCode() {

    auto student = get_student(0); std::cout << "ID: 0, "
        << "GPA: " << std::get<0>(student) << ", "
        << "Grade: " << std::get<1>(student) << ", "
        << "Name: " << std::get<2>(student) << '\n';

    double gpa;
    char grade;
    std::string name;



    std::tie(gpa, grade, name) = get_student(1);
    std::cout << "ID: 1, "
        << "GPA:" << gpa << ","
        << "Grade: " << grade << ", "
        << "Name: " << name << '\n';



}

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    typedef tuple< int, char, float > tp;
    tp t1(100, 'A', 100.111);
    tp t2(200, 'B', 200.222);
    tp t3 = make_tuple(300, 'C', 300.333);

    cout << tuple_size< tp >::value << endl;

    cout << get<0>(t1) << endl;
    cout << get<1>(t1) << endl;
    cout << get<2>(t1) << endl;

    int i = get<0>(t1);
    cout << i << endl;

    int first;
    char second;
    float third;

    tie(first, second, third) = t2;
    cout << " Displaying 2nd set t2 : " << first << endl;
    cout << " Displaying 2nd set t2 : " << second << endl;
    cout << " Displaying 2nd set t2 : " << third << endl;

    tie(first, second, third) = make_tuple(303, 'z', 303.339);
    cout << " Displaying 2nd set t3 : " << first << endl;
    cout << " Displaying 2nd set t3 : " << second << endl;
    cout << " Displaying 2nd set t3 : " << third << endl;

    get<0>(t3) = 223344;

    auto [first_1, second_2, third_3] = t3;

    cout << " Displaying 2nd set t3 via auto : " << first_1 << endl;
    cout << " Displaying 2nd set t3 via auto  : " << second_2 << endl;
    cout << " Displaying 2nd set t3 via auto  : " << third_3 << endl;


    typedef tuple< int, function< int(int) > > tp_fun;
    tp_fun tfun(101, [](int val) -> int {cout << " Lambda called " << val << endl; return 0; });

    get<1>(tfun)(107);

    // also add lambda here

    get<1>(tfun) = [](int val) -> int { cout << " Yet Another Lambda fun " << val << endl; return -1; };

    get<1>(tfun)(107);

    // creating tuples using vector

    vector<tp_fun> v;
    v.push_back(tfun);

    return 0;
}