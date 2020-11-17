#include <iostream>
#include <math.h>
using namespace std;
bool simple_test(int number)
{
    for(int i = 2; i < (int)sqrt(number); i++) if(number % i == 0) return false;
    return true;
}
bool correct_test(int number)
{
    int last_number = number % 10;
    while(number > 10)
    {
        number /=10;
        if(last_number >= number % 10) return false;
        else last_number = number % 10;
    }
    return true;
}
int main()
{
    int a, b;
    bool zero = true;
    cin >> a >> b;
    for(int i = a; i < b; i++) if(simple_test(i) && correct_test(i)){zero = false; cout << i << " ";}
    if(zero) cout << "0";
    return 0;
}