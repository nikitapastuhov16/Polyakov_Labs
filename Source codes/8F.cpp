#include <iostream>

using namespace std;
void sort(int *mass, int size)
{
    int min = 0;
    int max = size - 1;
    while (min < max)
    {
        for(int i = min; i < max; i++) if(mass[i] > mass[i+1]) swap(mass[i], mass[i+1]);
        max--;
        for(int i = max; i > min; i--) if(mass[i] < mass[i-1]) swap(mass[i], mass[i-1]);
        min++;
    }
}
int main()
{
    int a;
    cin >> a;
    int *mas = new int[a];
    for(int i = 0; i < a; i++) cin >> mas[i];
    sort(mas, a);
    for(int i = 0; i < 3; i++) cout << mas[i] << " ";
    return 0;
}