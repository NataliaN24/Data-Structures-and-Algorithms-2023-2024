#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
using namespace std;


int main()
{
    int n, q;
    cin >> n;
    vector<int>arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        
    }
   sort(arr.begin(),arr.end());
    cin>>q;
    while(q--)
    {
        int query;
        cin>>query;
        
        auto lower=lower_bound(arr.begin(),arr.end(),query);
        auto upper=upper_bound(arr.begin(),arr.end(),query);
        
        if(lower!=upper)
        {
            cout<<lower-arr.begin()<<" "<<upper-arr.begin()-1<<endl;
        }
        else{
              cout<<lower-arr.begin()<<endl;
        }
    }
}
