#include<iostream>

int logic(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return (n + logic(n-1));
    }
}
int main()
{
    int result =logic(3);
    std::cout<<"Result : "<<result<<std::endl;
    return 0;
}