#include <iostream>

using namespace std;
int reverse(int a)
{
    int i = a % 10;
    while(a / 10 != 0)
    {
        a /= 10;
        i *= 10;
        i += a%10;
    }
    return i;
}


int main()
{
    int a;
    cin >> a;
    cout << reverse(a);
    return 0;
}