#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word = "", temp;
    long unsigned int max = 0;
    while(cin >> temp) if(max < temp.length()) { max = temp.length(); word = temp; }
    cout << word << endl << max;
    return 0;
}