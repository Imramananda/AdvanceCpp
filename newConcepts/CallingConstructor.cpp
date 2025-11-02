#include<iostream>
using namespace std;

struct Timer
{
    Timer()
    {
        cout<<"Rama Timer constructor "<<endl;
    }
};

void demo()
{
    cout<<"Demo_1 "<<endl;
    Timer t();
    cout<<"Demo_2"<<endl;
    Timer tr{};
    cout<<"Demo_3"<<endl;
    Timer t1;
}

int main()
{
    demo();
    return 0;
}