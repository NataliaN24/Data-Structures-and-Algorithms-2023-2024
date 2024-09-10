#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
using namespace std;


int main() {

    string s;
    unordered_map<string, int>count;
    vector<string>arr;
    while (cin>>s)
    {
      
        count[s]++;
    }
    for (auto& pair : count)
    {
        if (pair.second<2)
        {
            arr.push_back(pair.first);
        }
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << endl;
    }
}
