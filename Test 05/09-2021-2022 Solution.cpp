#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    unordered_map<string, int>arr;
    vector<string>words;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        words.push_back(str);
        arr[str]++;
    }
    for (const string&w :words) {
        
       cout<<arr[w]<<" ";
    }
}
