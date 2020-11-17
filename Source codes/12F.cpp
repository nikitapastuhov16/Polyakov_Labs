#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector<string> split(string value, string separator)
{
    vector<string> splited;
    char* token = strtok((char*)value.c_str(), (char*)separator.c_str());
    while(token != NULL) {splited.push_back(string(token)); token = strtok(NULL, (char*)separator.c_str());}
    return splited;
}

bool comparer(string a, string b)
{
    return split(a," ")[1] < split(b," ")[1];
}

int main()
{
    vector<string> names;
    string input;
    getline(cin, input);
    while(!input.empty()) 
    {
        names.push_back(input);
        getline(cin, input);
    }
    sort(names.begin(), names.end(), comparer);
    
    for(int i = 0; i < names.size(); i++) 
    {
        cout<<to_string(i+1) + ". " + names[i]<<endl;
    }
    return 0;
}
