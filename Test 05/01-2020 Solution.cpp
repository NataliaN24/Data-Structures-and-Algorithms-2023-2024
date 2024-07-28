#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int M;
    cin >> M;
    vector<unordered_set<int>> adj(M);

    for (int i = 0; i < M; i++) {
        int Ni;
        cin >> Ni;
        for (int j = 0; j < Ni; ++j) {
            int neighbor;
            cin >> neighbor;
            adj[i].insert(neighbor);
            adj[neighbor].insert(i); 
        }
    }

    int Q;
    cin >> Q;
    vector<int> result(Q, 1);

   
    for (int i = 0; i < Q; i++) {
        int Lj;
        cin >> Lj;
        vector<int> path(Lj);
        for (int j = 0; j < Lj; ++j) {
            cin >> path[j];
        }

        for (int j = 0; j < Lj - 1; ++j) {
            if (adj[path[j]].find(path[j + 1]) == adj[path[j]].end()) {
                result[i] = 0;
                break;
            }
        }
    }

    
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
