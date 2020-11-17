#include <iostream>

using namespace std;

int main()
{
    int a, n;
    cin >> a >> n;
    int *mas = new int[n];
    for(int i = 1; i <= n; i++)
    {
        mas[i-1] = a + n - i;
        cout << mas[i-1] << " ";
    }
    return 0;
}