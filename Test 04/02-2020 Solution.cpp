----------------------------------------------------------------FIRST SOLUTION------------------------------------------------------------------------------------------
  #include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(const vector<int>& arr, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return true;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int target = arr[i] - arr[j];
            if (target < arr[j]) continue;
            if (binarySearch(arr, j + 1, i - 1, target)) {
                cout << "true" << endl;
                return 0;
            }
        }
    }

    cout << "false" << endl;
    return 0;
}
------------------------------------------------------SECOND SOLUTION------------------------------------------------------------------------------------------------
  #include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool calculate(const vector<int>&weights){
    
    unordered_map<int,int>arr;
    
    int n=weights.size();
    
    for(int i=0;i<n;i++){
        arr[weights[i]]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            int target=weights[i]-weights[j];
            if(arr.find(target)!=arr.end()){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> weights(N);
    for (int i = 0; i < N; ++i) {
        cin >> weights[i];
    }
    if(calculate(weights)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
