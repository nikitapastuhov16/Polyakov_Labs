#include <iostream>
#include <set>
#include <string>
using namespace std;
bool contains(string str, char find)
{
    for(int i = 0; i < str.size(); i++) if(str[i] == find) return true;
    return false;
}
int main()
{
    set<char> numbers, latinLetters;
    for(char i = '0'; i <= '9'; i++) numbers.insert(i);
    for(char i = 'a'; i <= 'z'; i++) latinLetters.insert(i);
    string variable;
    getline(cin, variable);

    if(latinLetters.find(tolower(variable[0])) == latinLetters.end() && 
    variable[0] != '_')
    { cout << "NO"; return 0; }
    
    else 
    {
        for(int i = 1; i < variable.size(); i++) 
        {
            if((numbers.find(variable[i]) == numbers.end()) && 
            (latinLetters.find(tolower(variable[i])) == latinLetters.end()) &&
            variable[i] != '_')
            {
                cout << "NO"; return 0;
            }
        }
    }
    cout << "YES";
    
    return 0;
}