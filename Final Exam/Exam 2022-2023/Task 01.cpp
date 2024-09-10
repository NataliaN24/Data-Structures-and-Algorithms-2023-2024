#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    unordered_map<int, int>count;
    vector<int>brother(n);
    int fight = 0;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> brother[i];
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
        if (count[brother[i]] == 0) {
            fight++;
        }
        else {
            count[brother[i]]--;
        }
    }


    cout << fight << endl;
}