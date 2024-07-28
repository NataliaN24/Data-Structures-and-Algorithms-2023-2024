#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include<cstring>
using namespace std;

int n, minX, maxX, minY, maxY;
vector<vector<int>> g;
vector<int> areas;
pair<int, int> directions[4] = { {-1,0},{0,1},{1,0},{0,-1} };

bool isValid(int r, int c)
{
    return ((r >= 0 && r < n) && (c >= 0 && c < n) && g[r][c] == 1);
}

void dfs(int r, int c)
{
    if (r < minX)
        minX = r;

    if (r > maxX)
        maxX = r;

    if (c < minY)
        minY = c;

    if (c > maxY)
        maxY = c;

    g[r][c] = 0;

    for (int i = 0; i < 4; i++)
    {
        int neighbor_i = r + directions[i].first;
        int neighbor_j = c + directions[i].second;

        if (isValid(neighbor_i, neighbor_j))
            dfs(neighbor_i, neighbor_j);
    }
}

void find()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 1)
            {
                minX = INT_MAX;
                maxX = INT_MIN;

                minY = INT_MAX;
                maxY = INT_MIN;

                dfs(i, j);

                int area = (maxX - minX + 1) * (maxY - minY + 1);

                areas.push_back(area);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    g.resize(n);

    for (int i = 0; i < n; i++)
        g[i].resize(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    find();

   sort(areas.begin(), areas.end());

    for (int i = areas.size() - 1; i >= 0; i--)
        cout << areas[i] << ' ';
}
