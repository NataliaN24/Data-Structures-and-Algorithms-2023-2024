#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
bool isEqual(const string& s) {
    unordered_map<char, int>count;
    for (char ch : s) {

        count[ch]++;
    }
    unordered_map<int, int>freqcount;
    for (const auto& p : count) {
        freqcount[p.second]++;
    }
    if (freqcount.size() == 1) {
        auto it = freqcount.begin();
        int freq = it->first;
        if (freq == 1 || it->second == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (freqcount.size() == 2) {
        auto it = freqcount.begin();
        int freq1 = it->first;
        int count1 = it->second;
        it++;
        int freq2 = it->first;
        int count2 = it->second;
        if (freq1 > freq2) {
            swap(freq1, freq2);
            swap(count1, count2);
        }
        if (freq1 == 1 && count1 == 1) {
            return true;
        }
        if (freq2 == freq1 + 1 && count2 == 1) {
            return true;
        }
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    cin >> n;
    vector<string>str(n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    for (const string& s : str) {
        cout << (isEqual(s) ? 1 : 0) << endl;
    }

    return 0;
}