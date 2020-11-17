#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int ** matrix = new int*[m];
    int maximum = 0;
    int *maximums = new int[n];
    for(int i = 0; i < n; i++)
    {
        maximums[i] = 0;
    }
    for(int i = 0; i < m; i++)
    {
        matrix[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            if(maximum < matrix[i][j]) maximum = matrix[i][j];
            if(maximums[j] < matrix[i][j]) maximums[j] = matrix[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(maximum == maximums[i])
        {
            for(int j = 0; j < m; j++)
            {
                cout << matrix[j][i];
                if(m - j == 1) cout <<"\n";
                else cout << " ";
            }
        }
    }
    return 0;
}