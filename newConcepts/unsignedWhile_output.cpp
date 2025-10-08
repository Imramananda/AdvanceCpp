#include<iostream>
int main()
{
    int i = 1000;
     // This while loop increments i until it becomes 0
     while (i++ != 0);
     std::cout << i << std::endl;
 
    for(int i=0; i<5;++i)
    {
        if(i==3)
        {
            continue;
        }
        std::cout<<i<<std::endl;
    }
    return 0;
}