#include <iostream>

using namespace std;

int main()
{
    int month;
    cin >> month;
    if ((month > 0 && month < 3) || month == 12)      cout << "winter";
    else if (month > 2 && month < 6 )                 cout << "spring";
	else if (month > 5 && month < 9 )                 cout << "summer";
	else if (month > 8 && month < 12)                 cout << "autumn";
	else                                              cout << "NO"    ;
}