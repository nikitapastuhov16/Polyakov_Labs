#include <iostream>
#include <string>
using namespace std;
string converter(int number)
{
    string a = "";
    while (number - 1000 >= 0) { a += "M" ;  number -= 1000; }
    while (number - 900  >= 0) { a += "CM";  number -= 900 ; }
    while (number - 500  >= 0) { a += "D" ;  number -= 500 ; }
    while (number - 400  >= 0) { a += "CD";  number -= 400 ; }
    while (number - 100  >= 0) { a += "C" ;  number -= 100 ; }
    while (number - 90   >= 0) { a += "XC";  number -= 90  ; }
    while (number - 50   >= 0) { a += "L" ;  number -= 50  ; }
    while (number - 40   >= 0) { a += "XL";  number -= 40  ; }
    while (number - 10   >= 0) { a += "X" ;  number -= 10  ; }
    while (number - 9    >= 0) { a += "IX";  number -= 9   ; }
    while (number - 5    >= 0) { a += "V" ;  number -= 5   ; }
    while (number - 4    >= 0) { a += "IV";  number -= 4   ; }
    while (number - 1    >= 0) { a += "I" ;  number -= 1   ; }
    return a;
}
int main()
{
    int a;
    cin >> a;
    cout << converter(a);
    return 0;
}