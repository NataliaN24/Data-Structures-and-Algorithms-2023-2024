#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
-------------------------------------------------------FIRST SOLUTION (WITHOUT USING STD::SORT)-------------------------------------------------------------------------------------
void merge(int* arr1, int l1, int* arr2, int l2) {
    int c1=0, c2=0, recursor = 0;
    int* finalArr = new int[l1 + l2];
    while (c1 < l1 && c2 < l2) {
        if (arr1[c1] < arr2[c2]) {
            finalArr[recursor++] = arr1[c1++];

        }
        else {
            finalArr[recursor++] = arr2[c2++];

        }
    }
    while (c1 < l1) {
        finalArr[recursor++] = arr1[c1++];
    }
    while (c2 < l2) {
        finalArr[recursor++] = arr2[c2++];
    }
    int finalLen = l1 + l2;
    for (int i = 0; i < finalLen; i++) {
        arr1[i] = finalArr[i];
    }
    delete[]finalArr;
}

void mergeSort(int* arr, int len) {
    if (len <= 1) {
        return;
    }
    int mid = len / 2;
    mergeSort(arr, mid);
    mergeSort(arr + mid, len - mid);
    merge(arr, mid, arr + mid, len - mid);
}
int main() {

    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, n);
    cout<<arr[0]<<" ";
    for (int i = 1; i < n; i++) {
        if (arr[i]!=arr[i-1]){
            cout<<arr[i]<<" ";
        }
      }
}
----------------------------------------SECOND SOLUTION (USING STD::SORT)------------------------------------------------------------------------------------------

#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    vector<int>result;
    result.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            result.push_back(arr[i]);
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}
