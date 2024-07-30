#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void traverse(int start, int dest, vector<int>& comps, vector<unordered_set<int>>& roads) {
    if (comps[start] != 0)
        return;

    comps[start] = dest;

    for (int nbr : roads[start]) {
        traverse(nbr, dest, comps, roads);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<unordered_set<int>> roads(N + 1);

    for (int i = 0; i < M; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        roads[c1].insert(c2);
        roads[c2].insert(c1);
    }

    vector<int> comps(N + 1, 0);
    int current = 1;

    for (int i = 1; i <= N; ++i) {
        if (comps[i] == 0) {
            traverse(i, current, comps, roads);
            ++current;
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int t, c1, c2;
        cin >> t >> c1 >> c2;

        if (t == 2) {
            if (comps[c1] == comps[c2])
                continue;

            int target = comps[c2];
            for (int j = 1; j <= N; ++j) {
                if (comps[j] == target)
                    comps[j] = comps[c1];
            }
        }
        else {
            cout << (comps[c1] == comps[c2]);
        }
    }

    return 0;
}
