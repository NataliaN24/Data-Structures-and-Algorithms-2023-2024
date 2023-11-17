#include <iostream>
#include <set>
#include <iterator>
#include <climits>

using namespace std;
long long res = LLONG_MAX;
long long Q;
set<long long> S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;

    
    S.insert(0);

    for (long long i = 0; i < Q; i++)
    {
        long long num;
        cin >> num;

        auto el = S.insert(num);

        set<long long>::iterator it1 = el.first;

        if (next(it1) != S.end())
        {
            long long smallEl = min(*prev(it1) ^ *it1, *next(it1) ^ *it1);
            res = min(smallEl, res);
        }
        else
        {
            res = min(*prev(it1) ^ *it1, res);
        }

        cout << res << endl;
    }

    return 0;
}
