#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
-------------------------------------------------------FIRST SOLUTION------------------------------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;
    unordered_map<long long, long long> count;
    for (int i = 0; i < n; i++) {
        int num;
        cin>>num;
   
        count[num]++;
    }
    
   int sum = 0;
   for(const auto&pair:count){
       if(pair.second%2!=0){
           sum+=pair.first*pair.second;
       }
   }
    cout << sum;
    return 0;
}

-------------------------------------------------------SECOND SOLUTION------------------------------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;
    unordered_map<int, int> count;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
       cin >> arr[i];
        count[arr[i]]++;
    }
    
  int sum = 0;
    for (int i = 0; i < n; i++) {
        if (count[arr[i]] % 2 != 0) {
            sum += arr[i];
        }
    }
    
    cout << sum;
    return 0;
}
