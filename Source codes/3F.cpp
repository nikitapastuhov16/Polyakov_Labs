#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int a, b, n;
    cin >> a >> b >> n;
    for(int i = 0; i < n; i++) cout << rand()%(b-a+1)+a<< " ";
    return 0;
}