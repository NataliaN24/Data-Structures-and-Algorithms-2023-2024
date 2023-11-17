//It is not the right solution
#include <iostream>
#include <vector>

using namespace std;

vector<pair<long long, long long>> tree;
long long n;
long long maxprod = 0;

long long calculateProduct(long long node) {
    if (node == -1) {
        return 0;
    }

    long long lhs = calculateProduct(tree[node].first);
    long long rhs = calculateProduct(tree[node].second);

    long long product = static_cast<long long>(n - lhs - rhs) * lhs * rhs;
    maxprod = max(maxprod, product);

    return lhs + rhs + 1;
}

int main() {
    cin >> n;
    tree.resize(n, {-1, -1});

    for (long long i = 0; i < n; i++) {
        cin >> tree[i].first >> tree[i].second;
    }

    long long productWithoutRoot = calculateProduct(0);
    maxprod = productWithoutRoot;

    if (tree[0].first != -1) {
        long long productWithoutLeft = calculateProduct(tree[0].first);
        maxprod = max(maxprod, productWithoutLeft);
    }

    if (tree[0].second != -1) {
        long long productWithoutRight = calculateProduct(tree[0].second);
        maxprod = max(maxprod, productWithoutRight);
    }

    cout << maxprod << endl;

    return 0;
}
