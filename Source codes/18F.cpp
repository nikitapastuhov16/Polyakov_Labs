#include <iostream>

#include <list>
#include <vector>

#include <sstream>
#include <fstream>

#include <string>
#include <cstring>

using namespace std;
template <typename T>
string toString(T val)
{
    ostringstream stream;
    stream << val;
    return stream.str();
}
void replace(string &input, const string &string_to_replace, const string &replacement_string)
{
    size_t pos = input.find(string_to_replace);
    while(pos != string::npos)
    {
        input.replace(pos, pos + string_to_replace.size(), replacement_string);
        pos = input.find(string_to_replace, pos);
    }
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
    list<string> text;
    ifstream commands;
    commands.open("input.txt");
    string line;
    while(getline(commands, line))
    {
        if(line[0] == '+')
        {
            vector<string> splited = split(line, " ");
			
            string line2 = splited[0];
            replace(line2, "+", "");
            int index = atoi(line2.c_str());
            if(index-1 > (int)text.size() && text.size() != 0)
            {
                ofstream output;
                output.open("output.txt");
                output << "ERROR";
                output.close();
                commands.close();
                return 0;
            }
            auto iterator = text.begin();
            advance(iterator, index - 1);
            string to_replace = line;
            replace(to_replace, "+" + toString(index) + " ", "");
            text.insert(iterator, to_replace);
            continue;

        }
        else if(line[0] == '*')
        {
            vector<string> splited = split(line, " ");
            string line2 = splited[0];
            replace(line2, "*", "");
            int index = atoi(line2.c_str());
            if(index > (int)text.size())
            {
                ofstream output;
                output.open("output.txt");
                output << "ERROR";
                output.close();
                commands.close();
                return 0;
            }
            auto iterator = text.begin();
            advance(iterator, index - 1);
            auto erased = text.erase(iterator);
            string to_replace = line;
            replace(to_replace, "*" + toString(index) + " ", "");
            text.insert(erased, to_replace);
            continue;
        }
        else if(line[0] == '-')
        {
            string line2 = line;
            replace(line2, "-", "");
            int index = atoi(line2.c_str());
            if(index > (int)text.size())
            {
                ofstream output;
                output.open("output.txt");
                output << "ERROR";
                output.close();
                commands.close();
                return 0;
            }
            auto iterator = text.begin();
            advance(iterator, index - 1);
            auto erased = text.erase(iterator);
            continue;
        }
        else
        {
            ofstream output;
            output.open("output.txt");
            output << "ERROR";
            output.close();
            commands.close();
            return 0;
        }  
    }
    if(text.size() == 0)
    {
        ofstream output;
        output.open("output.txt");
        output << "EMPTY";
        output.close();
        commands.close();
        return 0;
    }
    else
    {
        auto iterator = text.begin();
        ofstream output;
        output.open("output.txt");
        output << *iterator;
        iterator++;
        for(iterator; iterator != text.end(); ++iterator)
        {
            output << endl << *iterator;
        }
        output.close();
		commands.close();
    }
    return 0;
}