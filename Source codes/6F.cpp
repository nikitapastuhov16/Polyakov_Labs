#include <iostream>

using namespace std;
int count(int a)
{
    if(a == 0)               return 0;
    int i        =               a/10;
    int j        = (a%2 == 0) ? 1 : 0;
    return               count(i) + j;
}


int main()
{
    int a;
    cin >> a;
    cout << count(a);
    return 0;
}