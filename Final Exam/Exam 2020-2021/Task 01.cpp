#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int>arr1(n);

    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    sort(arr1.begin(), arr1.end());

    for (int i = 0; i < m; i++)
    {
        cin >> num;
        int count = lower_bound(arr1.begin(), arr1.end(), num) - arr1.begin();
        cout << count << " ";

    }

}
