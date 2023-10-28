#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool   binarySearch(long long arr[],long long l,long long r,long long x){
   while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return true;
 
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return false ;
}

int main() {
    long long n = 0; 
    long long d = 0;
    cin>>n>>d;
    long long* arr = new long long[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    } 
    sort(arr, arr + n);
    int counter=0;
    for(int i=0;i<n;i++){
        if(binarySearch(arr,0,n-1,arr[i]+d)){
            counter++;
        }
    }
    cout<<counter;
    return 0;
}
