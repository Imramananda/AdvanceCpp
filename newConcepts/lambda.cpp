#include <iostream>
using namespace std;

int main()
{
    auto f = [](int a)
    {
        cout << "Lambda function " << endl;
        return a * a;
    };

    cout << f(10) << endl;
    return 0;
}
