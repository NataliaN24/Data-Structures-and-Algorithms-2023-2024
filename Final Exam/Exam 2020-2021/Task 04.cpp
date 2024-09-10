#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_set>
using namespace std;


int main() {
    int n;
    cin >> n;
    unordered_set<int>set;
    vector<int>num(n);
    int start=0;
    int end=0;
     int length = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        
    }
   
    while(end<n)
    {
        if(set.find(num[end])==set.end())
        {
            set.insert(num[end]);
            length=max(length,end-start+1);
            
            end++;
        }
        else{
            set.erase(num[start]);
            start++;
        }
    }
    cout<<length;
}
