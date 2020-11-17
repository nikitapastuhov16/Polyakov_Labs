#include <iostream>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int *mass = new int[n];
    for(int i = 0; i < n; i++) cin >> mass[i];
    int l = 1, r = 1e9;
    while(l<r)
    {
        int m = (l+r)/2;
        int kn = 0;
        for(int i = 0; i < n; ++i) kn += mass[i]/m;
        if(kn>=k) l = m+1;
        else r = m;
    }
    cout << l-1;
    return 0;
}