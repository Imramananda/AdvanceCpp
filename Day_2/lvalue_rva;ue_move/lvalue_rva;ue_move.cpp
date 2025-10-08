//
//  main.cpp
//  28_SI_lValue_rValue_move
//
//  Created by Sathya Babu on 28/05/24.
//

#include <iostream>
#include <vector>
using namespace std;
int foo() { return 123; }

// Phase II

class Widget {
public:
    void doWork1()&
    {
        cout << "Working on lValue object" << endl;
    }
    void doWork()&&
    {
        cout << "Working on rValue object" << endl;
    }
};
// A complete understanding goes here..

class Widget_Vec {
public:
    using DataType = std::vector< double >;

    Widget_Vec() {
        values = { 1.0,2.20,3.30,4.40 };
    }
    DataType& data()&
    {
        return values;
    }
    DataType data()&&
    {
        return  std::move(values);  // DIRTY code :  A bettery is getting via a perfect forward..
    }
private:
    DataType values;
};

std::string makeCat()
{
    return "Percian Cat";
}
//------------------- Creating MyVector -----------------------

class MyVector {
public:
    // Lets get the regiular constructor
    MyVector(int i) : size(i)
    {
        cout << "-> Landed in rergular constructor ...." << endl;
        elements = new int[i];

        for (int j = 0; j < i; j++) {
            elements[j] = j;
        }
    }
    //    ~MyVector(){
    //        cout << "-> Landed in rergular Destructorr ...." << endl ;
    //    }
    //    
        // copy constructor
    //    MyVector( const MyVector& other ) : size( other.size)
    //    {
    //        cout << "-> Landed in Copy Constructor...." << endl ;
    //        elements = new int[ other.size ];
    //        
    //        for( int i = 0 ; i <= other.size ; ++i){
    //            elements[ i ] = other.elements[ i ];
    //        }
    //        
    //    }
    //    


        // perfect forwarding how a var can be figured out if its rValue or lValue?

        // rValue constructor :  move construct
    MyVector(MyVector&& other) : size(0), elements(nullptr)
    {
        cout << "-> Landed in *** rValue  Constructor...." << endl;
        // Phase I

//        elements = other.elements;
//        size = other.size ;
//        
//        // Lets clean up the var
//        other.elements = nullptr;
//        other.size     = 0 ;

        // Phase II

        //-----------

        std::swap(elements, other.elements);
        std::swap(size, other.size);

        // swap( other );



    }
    //    void  swap( MyVector& other ){
    //        
    //        std::swap( elements,other.elements);
    //        std::swap( size,other.size);
    //        
    //    }
    //    
    int getSize() { return size; }

    int& operator [] (int index) {
        cout << " ---> operator[](int index ) [] ";
        return  elements[index];
    }
    //    private :
    int* elements;
    int size;
};  // MyVector ends

// this is a part of the iterator
int* begin(MyVector& v) {
    cout << " begin() " << endl;
    // return v.getSize()!=0 ? &v[ 0] : nullptr;
    return v.elements;
}

int* end(MyVector& v) {
    cout << " end() " << endl;
    return v.getSize() != 0 ? &v[0] + v.getSize() : nullptr;

    // return v.elements + v.size ;
}

//------------------- End of  MyVector -----------------------

//--------- Supporting function for the above MyVector ends here

// ------------------------  creating our own class which generates rValue object
class MyClass {
public:
    int data;

    //     *****  Next phase   ******
    //    MyClass(int& value) {  // without int& value creates conflict
    //        data = value;
    //      //  data = new int(std::move(value));
    //        std::cout << "lValue  constructor called\n";
    //    }

    MyClass(int&& value) {
        data = value;
        //  data = new int(std::move(value)); // for this line destructor required
        std::cout << "Move constructor called rValue Move \n";
    }

    // not necessary
    ~MyClass() {
        // delete data; //Thread 1: signal SIGABRT
    }
};

int myFunction() {
    return 123;
}
MyClass createObject() {
    std::cout << "Creating Object" << std::endl;
    MyClass obj(5);  // Move constructor called
    // obj.printData();
    return obj;   //  rValue
}

//-----------------------------------------------------------------------------

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Expressions !\n";

    int* arr; int* p; int x; int y;

    // lValue
    int i = 10;  // this is not a lValue

    x;
    *p;
    arr[0];

    // rValue are also called as xValue

    12;
    x + y;
    foo();

    // lvalue
    // remember lValue takes only lValue
    int& lValue = x;
    // error
    //int& lValue = 300 ;

    // rValue
    // remember rValue takes only rValue

    int&& rValue = 321; // correct..

    // WRONG****
//   int ii = std::move( i ) ; // converts any thing and evry thing to rValue
    int&& ii = std::move(i);

    // Variables should never be declared as l_r_value
    const int& l_r_Value = x;

    // prValue
    nullptr_t myVar;

    //NULL myNull ;( void*)0
   // use nullptr

    //-------------------------------------------


    // Lets implement  Widget

    Widget wideget1;
    wideget1.doWork1();    // returns lValue

    Widget().doWork();   // returns rValue

    // A clear concept

    Widget_Vec widget;

    cout << "Data for lValue objects: " << endl;
    for (const auto& value : widget.data()) {
        cout << value << " ";

    }
    cout << "Accesing data  for rValue objects: " << endl;
    for (const auto& value : Widget_Vec().data()) {
        cout << value << " ";

    }
    cout << endl;

    //-------------------------------------------

    std::string s("Cat"); // Constructor gets called...
    std::string s2(s);  // Copy constructor OUT DATED and ELEMENATED
    std::string s3(makeCat()); // rValue  Going to be a disauster

    std::string s34(std::move(makeCat()));

    // Our implementation...

    MyVector v1(5);    // what gets called..
    // MyVector v2 (  v1 ); // Copy Constructor....
    //    MyVector v3 (  MyVector( 2 ) ); // Copy constructor

       // MyVector v4 (    static_cast< MyVector&& >( v1 ) ); // rValue

    MyVector  v5(std::move(v1));// rValue
    // MyVector v6 = v1 ;  // ERRRORRRRR......
  //    MyVector  v5 ( 234 );// will not work since its a rValue


     // MyVector  v5  = myRvalue(2323);
     // MyVector  v7 ( myRvalue(2323) );

      //-------------------

    int value = 123;
    MyClass obj(value + 1);
    cout << " Obj..data " << obj.data << endl;

    MyClass obj2(myFunction());
    MyClass obj6 = createObject();
    MyClass obj66(createObject());

    MyClass lval2(10);  // rvalue

    int a = 10;
    //MyClass lVal( a );  // not work since its lValue
    return 0;
}