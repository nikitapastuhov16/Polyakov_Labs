#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream file;
    file.open("input.txt");
    string get;
    vector<int> numbers;
    while(file >> get)
    {
        if(get != "0") numbers.push_back(atoi(get.c_str()));
        else file.close();
    }
    int length = (numbers.size() + (numbers.size() % 2))/2;
    int *compressed = new int[length];
    for(int i = 0; i < length; i++)
    {
        if(length - i == 1 && numbers.size() % 2 == 1) compressed[i] = numbers[i];
        else compressed[i] = numbers[i] + numbers[numbers.size() - i - 1];
    }
    ofstream file2;
    file2.open("output.txt");
    for(int i = 0; i < length; i++) file2 << compressed[i] << endl;
    file2.close();
    return 0;
}