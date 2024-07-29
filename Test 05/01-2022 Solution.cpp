#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

------------------------------------------------------------------------FIRST SOLUTION-----------------------------------------------------------------------------
int main() {
    unordered_map<string, int>countA, countB;
    string word;
    while (cin >> word) {
        countA[word]++;
        if (cin.peek() == '\n') {
            break;
        }

    }
    while (cin >> word) {
        countB[word]++;
        if (cin.peek() == '\n') {
            break;
        }
    }
    vector<string>result;
    for (const auto& ch : countA) {
        if (ch.second == 1 && countB.find(ch.first) == countB.end()) {
            result.push_back(ch.first);

        }
    }
    for (const auto& ch : countB) {
        if (ch.second == 1 && countA.find(ch.first) == countB.end()) {
            result.push_back(ch.first);

        }
    }
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}
------------------------------------------------------------------------SECOND SOLUTION-----------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    map<string, int>count;
    string word;
    while(cin>>word){
        count[word]++;
    }
    for(const auto&ch :count){
        if(ch.second==1){
            cout<<ch.first<<endl;
        }
    }
    
}
