#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int first, sec;
        cin >> first >> sec;
        vector<string> arr1(first);
        vector<string> arr2(sec);
        
        for (int i = 0; i < first; ++i) {
            cin >> arr1[i];
        }
        
        for (int i = 0; i < sec; ++i) {
            cin >> arr2[i];
        }
        
        unordered_map<string, int> count;
        
        for (const auto& word : arr1) {
            count[word]++;
        }
        
        bool found = true;
        
        for (const auto& w : arr2) {
            if (count.find(w) == count.end() || count[w] == 0) {
                found = false;
                break;
            } else {
                count[w]--;
            }
        }
        
        if (found) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
