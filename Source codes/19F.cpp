#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;

bool isNumber(string &a)
{
    for(int i = 0; i < a.size(); ++i)
    {
        if(!isdigit(a[i])) return false;
    }
    return true;
}


vector<string> split(string value, string separators)
{
    vector<string> splited;
    char* token = strtok((char*)value.c_str(), (char*)separators.c_str());
    while(token != NULL) {splited.push_back(string(token)); token = strtok(NULL, (char*)separators.c_str());}
	return splited;
}

int main()
{
    string input_line;
    getline(cin, input_line);
    stack<double> numbers;
    vector<string> args = split(input_line, " ");
    for(int i = 0; i < args.size(); ++i)
    {
        if(isNumber(args[i]))
        {
            numbers.push(atoi(args[i].c_str()));
        }
        else if(!isNumber(args[i]))
        {
            if(args[i] == "+")
            {
                if(numbers.size() < 2) { cout << "ERROR"; return 0; }
                else
                {
                    double temp = numbers.top();
                    numbers.pop();
                    numbers.top() += temp;
                }
            }
            else if(args[i] == "-")
            {
                if(numbers.size() < 2) { cout << "ERROR"; return 0; }
                else
                {
                    double temp = numbers.top();
                    numbers.pop();
                    numbers.top() -= temp;
                }
            }
            else if(args[i] == "*")
            {
                if(numbers.size() < 2) { cout << "ERROR"; return 0; }
                else
                {
                    double temp = numbers.top();
                    numbers.pop();
                    numbers.top() *= temp;
                }
            }
            else if(args[i] == "/")
            {
                if(numbers.size() < 2) { cout << "ERROR"; return 0; }
                else
                {
                    double temp = numbers.top();
                    numbers.pop();
                    numbers.top() /= temp;
                }
            }
            else if(args[i] == "abs")
            {
                if(numbers.size() == 0) { cout << "ERROR"; return 0; }
                else
                {
                    double temp = numbers.top();
                    numbers.top() = abs(temp);
                }
            }
            else if(args[i] == "sqrt")
            {
                if(numbers.size()  == 0) { cout << "ERROR"; return 0; }
                else
                {
                    double temp = numbers.top();
                    numbers.top() = sqrt(temp);
                }
            }
            else if(args[i] == "sin")
            {
                if(numbers.size()  == 0) { cout << "ERROR"; return 0; }
                else
                {
                    double temp = numbers.top();
                    numbers.top() = sin(temp);
                }
            }
            else if(args[i] == "cos")
            {
                if(numbers.size()  == 0) { cout << "ERROR"; return 0; }
                else
                {
                    double temp = numbers.top();
                    numbers.top() = cos(temp);
                }
            }
        }
    }
    if(numbers.size() != 1) { cout << "ERROR"; return 0; }
    else
    {
        double intpart;
        if(modf(numbers.top(), &intpart) != 0) cout << fixed << setprecision(3) << numbers.top();
        else cout << (int)intpart;
    }
    
    return 0;
}