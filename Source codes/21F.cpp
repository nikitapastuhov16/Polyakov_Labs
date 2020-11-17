#include <iostream>
#include <vector>
using namespace std;
int sigma(int **matrix, int *cities, int matrix_size, int cities_count)
{
    int current_city, next_city, sigma = 0;
    for(int i = 1; i < cities_count; i++)
    {
        current_city = cities[i-1];
        next_city = cities[i];
        if(matrix[current_city-1][next_city-1] == 0) return 0;
        else sigma += matrix[current_city-1][next_city-1];
    }
    return sigma;
}
int main()
{
    int a;
    cin >> a;
    int **matrix = new int*[a];
    for(int i = 0; i < a; i++)
    {
        matrix[i] = new int[a];
        for(int j = 0; j < a; j++) cin >> matrix[i][j];
    }
    vector<int> cities;
    int b;
    while(cin >> b) cities.push_back(b);
    cout << sigma(matrix, &cities[0], a, cities.size());
    return 0;
}