#include<iostream>
#include<algorithm>
int main()
{
    int A[3];
    int B[3];
     // Input the die rolls for player A
    std::cout << "Enter the die rolls for player A: ";
    for (int i = 0; i < 3; ++i) {
        std::cin >> A[i];
    }

    // Input the die rolls for player B
    std::cout << "Enter the die rolls for player B: ";
    for (int i = 0; i < 3; ++i) {
        std::cin >> B[i];
    }
    std::sort(A, A + 3);
    std::sort(B, B + 3);
    int sumA = A[1] + A[2];
    int sumB = B[1] + B[2];
    if(sumA > sumB)
    {
        std::cout<<"Player A wins"<<std::endl;
    }
    else
    {
        std::cout<<"Player B wins"<<std::endl;
    }
    if(sumA == sumB)
    {
        std::cout<<"It's a draw"<<std::endl;
    }
    return 0;
}