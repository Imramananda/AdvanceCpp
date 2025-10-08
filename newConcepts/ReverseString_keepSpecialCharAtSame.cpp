#include <iostream>
#include <string>
#include <algorithm>

std::string reversString(std::string str)
{
    int l = 0;
    int r = str.length() - 1;
    while (l < r)
    {
        if (!isalpha(str[l]))
        {
            l++;
        }
        else if (!isalpha(str[r]))
        {
            r--;
        }
        else
        {
            std::swap(str[l], str[r]);
            l++;
           r--;
        }
    }
    std::cout << "Reversed String : " << str << std::endl;
    return str;
}

int main ()
{
    std::string str = "a!!!b.c.d,e'f,ghi";
    std::cout << "Original String : " << str << std::endl;
    std::string reverseStr = reversString(str);
    std::cout << "Reversed String : " << reverseStr << std::endl;
        return 0;
}