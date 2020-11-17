#include <iostream>
#include <vector>

using namespace std;
int optimal_vertex(int *mass, int startIndex, int k, int n)
{
    int optimalIndex = 0;
    int r = min(startIndex + k-1, n);
    for(int i = startIndex + 1; i <= r; i++)
    {
        if(mass[i] > 0) return i;
    }
    int max = mass[startIndex];
    optimalIndex = startIndex + 1;
    for(int i = startIndex+1; i < r; ++i) if(mass[i] > max) { max = mass[i]; optimalIndex = i; }
    return optimalIndex;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int *mas = new int[n];
    int sum = 0;
    vector<int> way;
    mas[0] = 0;
    mas[n-1] = 0;
    for(int i = 1; i < n-1; i++) cin >> mas[i];
    int j = 0;
    way.push_back(1);
    while(way.back() != n-1)
    {
        int optimal = optimal_vertex(mas, j, k, n);
        way.push_back(optimal+1);
        j = optimal;
        sum += mas[optimal];
    }
    way.push_back(n);
    if(sum < 0) sum = 0;
    cout << sum << endl << way.size() - 1 << endl;
    for(long unsigned int i = 0; i < way.size(); i++) cout << way[i] << " ";
    return 0;
}