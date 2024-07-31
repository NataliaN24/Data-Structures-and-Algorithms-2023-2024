#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

------------------------------------------------------FIRST SOLUTION-------------------------------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;

    vector<int>startTime(n);
    vector<int>endTime(n);
    for (int i = 0; i < n; i++) {
        cin >> startTime[i] >> endTime[i];
    }

    sort(startTime.begin(), startTime.end());
    sort(endTime.begin(), endTime.end());
    int i=0, j = 0;
    int maxOverlap=0, currentOverlap = 0;
    while (i < n && j < n) {
        if (startTime[i] < endTime[j]) {
            ++currentOverlap;
            maxOverlap = max(maxOverlap, currentOverlap);
            ++i;
        }
        else {
            --currentOverlap;
            ++j;
        }
    }
    cout << maxOverlap << endl;
}
------------------------------------------------------SECOND SOLUTION-------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
   int n;
    cin>>n;
    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++){
        int start;
        int end;
        cin>>start>>end;
        arr.push_back(make_pair(start,1));
        arr.push_back(make_pair(end,-1));
        
    }
    sort(arr.begin(),arr.end());
    
    int count=0,maxCount=0;
    for(const auto&i:arr){
        count+=i.second;
        maxCount=max(count,maxCount);
        
    }
    cout<<maxCount;
}
