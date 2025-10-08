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
    //std::cout << __PRETTY_FUNCTION__ << endl;

    cout << first << " , " << endl;  // 100, // 200,
    print(rest...);
    // if its literal push the same on to stack
    // if iys an op check for the pre... * /


}


int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Variadic expression..!\n";
    print( 1 );
    print( 100,200,300);
    print("First",1,"Second",2,"Third",3);  // class functions
    print(2, 3, 4, "*", "+");
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
/*
JSON
       {

          "id":4700,
          "logo_path":"/A32wmjrs9Psf4zw0uaixF0GXfxq.png",
          "name":"The Linson Company",
          "origin_country":"US"
       },
       {

          "id":25,
          "logo_path":"/qZCc1lty5FzX30aOCVRBLzaVmcp.png",
          "name":"20th Century Fox",
          "origin_country":"US"
       }
    ],
    "production_countries":[

       {

          "iso_3166_1":"US",
          "name":"United States of America"
       }
    ],
    "release_date":"1999-10-15",
    "revenue":100853753,
    "runtime":139,
    "spoken_languages":[

       {

          "english_name":"English",
          "iso_639_1":"en",
          "name":"English"
       }
    ],
    "status":"Released",
    "tagline":"Mischief. Mayhem. Soap.",
    "title":"Fight Club",
    "video":false,
    "vote_average":8.431,
    "vote_count":26043
}

*/