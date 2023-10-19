#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   int n=0;
    int q=0;
    cin>>n>>q;
    int upper=0;
    int lower=0;
    vector<int>students(n);
    
    for(int i=0;i<n;i++){
        cin>>students[i];
    }
    sort(students.begin(),students.end());
    for(int i=0;i<q;i++){
       
        cin>>lower>>upper;
        int low=lower_bound(students.begin(),students.end(),lower)-students.begin(); // lower_bound finds the iterator that points to the numbers which is not less than the lower.By substracting we find the exact index of the lower  
         int up=upper_bound(students.begin(),students.end(),upper)-students.begin(); // here we find the exact index of the first number which is greater than the upper
        int count=up-low;
        if(count<0){
            count=0;
        }
        cout<<count<<endl;
    }
    
    
    return 0;
}
