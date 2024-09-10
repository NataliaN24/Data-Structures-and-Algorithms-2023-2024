#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>arr(n, vector<int>(m));
    map<vector<int>, int>count;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
        count[arr[i]]++;
    }
    int uniqueCount = 0;
    for (const auto& el : count)
    {
        if (el.second == 1) {
            uniqueCount++;
        }
    }
    cout << uniqueCount;
}
