#include<iostream>
int main()
{
    int n;
    std::cout<<"Enter the size of the array : ";
    std::cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        std::cin>>a[i];
    }
    std::cout<<"Array : ";
    for(int i=0;i<n;++i)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
    int sum;
    std::cout<<"Enter the sum : ";
    std::cin>>sum;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(a[i]+a[j]==sum)
            {
                std::cout<<a[i]<<" "<<a[j]<<std::endl;
                std::cout<<i<<" "<<j<<std::endl;
            }
        }
    }

    return 0;
}