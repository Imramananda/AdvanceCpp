#include<iostream>
using namespace std;
int main()
{
 cout<<"Ram"<<endl;
 int *p=nullptr;
 //cout<<*p<<endl;
 int *q=new int;
 *q=10;
 cout<<*q<<endl;
 cout<<q<<endl;
 cout<<&q<<endl;
    return 0;
}
