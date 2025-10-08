
#include <iostream>
using namespace std;

typedef float f;
f fVar = 12.22f;

using ff = float;
ff fVar2 = 123.33;

using FP = void(*)(int);
void foo(FP);


template<typename  T>
void print(const T& t)
{
    cout << " In me " << t << endl;  // In me 300
}

template<typename  First, typename... Rest>
void print(const First& first, const Rest&... rest)
{
   // std::cout << __FUNCSIG__ << endl;

    cout << first << " , " << endl;  // 100, // 200,
    print(rest...);
}
int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Variadic expression..!\n";
    print( 1 );
    print( 100,200,300);
    print("First", 1, "Second", 2, "Third", 3);  // class functions
    return 0;
}
/*
Variadic expression..!
void print(const First &, const Rest &...) [First = char[6], Rest = <int, char[7], int, char[6], int>]
First ,
void print(const First &, const Rest &...) [First = int, Rest = <char[7], int, char[6], int>]
1 ,
void print(const First &, const Rest &...) [First = char[7], Rest = <int, char[6], int>]
Second ,
void print(const First &, const Rest &...) [First = int, Rest = <char[6], int>]
2 ,
void print(const First &, const Rest &...) [First = char[6], Rest = <int>]
Third ,
  In me 3
Program ended with exit code: 0
*/