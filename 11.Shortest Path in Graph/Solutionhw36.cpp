//it covers only 50/100  of edge cases

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y;
    Point(int i, int j) : x(i), y(j) {}
};

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows&& y >= 0 && y < cols;
}

int escapeTime(vector<vector<char>>& property) {
    int N = property.size();
    int M = property[0].size();
    vector<vector<int>> escapeTime(N, vector<int>(M, -1));

    queue<Point> q;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (property[i][j] == '.') {
                escapeTime[i][j] = 0;
                q.push(Point(i, j));
            }
        }
    }

  int maxTime = 0;
while (!q.empty()) {
    Point current = q.front();
    q.pop();

    maxTime = escapeTime[current.x][current.y]; 

    for (int k = 0; k < 4; ++k) {
        int nx = current.x + dx[k];
        int ny = current.y + dy[k];

        if (isValid(nx, ny, N, M) && property[nx][ny] == '.' && escapeTime[nx][ny] == -1) {
            escapeTime[nx][ny] = escapeTime[current.x][current.y] + 1;
            q.push(Point(nx, ny));
        }
    }
}

int maxTimeCells = 0;
for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
        if (property[i][j] == '.' && escapeTime[i][j] == maxTime) {
            maxTimeCells++;
        }
    }
}

return maxTimeCells;

}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> property(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> property[i][j];
        }
    }

    int result = escapeTime(property);
    cout << result << endl;

    return 0;
}
