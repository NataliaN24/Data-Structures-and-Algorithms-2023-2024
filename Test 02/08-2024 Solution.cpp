#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int binarySearch(vector<pair<int,int>>& arr, int left, int right, int x) {

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].first == x) {
            return mid;
        }
        else if (arr[mid].first < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;

}
int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int kg, num;
        cin >> kg >> num;
        vector<pair<int,int>>arr;


        for (int i = 0; i < num; i++) {
            int weight;
            cin>>weight;
            arr.push_back({weight,i+1});
        }
        sort(arr.begin(),arr.end());

        for (int i = 0; i < num; i++) {
            
            int complement = kg - arr[i].first;
            
            int res = binarySearch(arr, i + 1, num - 1, complement);
            
            if (res != -1) {
                cout <<min(arr[i].second,arr[res].second)  << " " <<max(arr[i].second,arr[res].second)<<endl;

                break;
            }
        }

    }


}
