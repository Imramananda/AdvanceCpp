// ReturnCheck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int f(int a)
{
    if (a == 2)
        return a;
    for(int i = 0; i < 5; i++)
    {
        std::cout << i << std::endl;
    }
    std::cout << "End of loop" << std::endl;
    return 0;
}

int main()
{
    std::cout << "Hello World!\n";
    std::cout<< f(2) <<std::endl;
    return 0;
}
