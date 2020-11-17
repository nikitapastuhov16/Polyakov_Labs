#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double number1, number2;
    cin >> number1 >> number2;
    cout << fixed << setprecision(3) << pow(number1, number2);
    return 0;
}