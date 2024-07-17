#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> binarySearch(vector<int>&arr,int left,int right,int x)
{
    int count=0;
    while(left<=right)
    {
        count++;
        int mid=left+(right-left)/2;
        if(arr[mid]==x)
        {
            return {mid,count};   
        }
        else if(arr[mid]<x)
        {
            left=mid+1;
        }
        else
        { 
            right=mid-1;
        }
    }
    return {-1,count};
}

int main() 
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int m;
    cin>>m;
    
    vector<int>indeces(m);
    vector<int>checks(m);
    
    vector<int>nums(m);
    for(int i=0;i<m;i++){
        cin>>nums[i];
        auto result=binarySearch(arr,0,n-1,nums[i]);
        indeces[i]=result.first;
        checks[i]=result.second;
            
    }
    for(int i=0;i<m;i++){
        cout<<indeces[i]<<" ";
    }
    cout<<endl;
     for(int i=0;i<m;i++){
        cout<<checks[i]<<" ";
    }
 
}
