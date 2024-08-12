#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
---------------------------------------------------FIRST SOLUTION---------------------------------------------------------------------------------------------------
void counting_sort(long long* arr, long long arrLength) {
    int* arr_copy = new int[arrLength];

    int max = arr[0];
    for (int i = 0; i < arrLength; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
        arr_copy[i] = arr[i];
    }

    int* count = new int[max + 1];
    for (int i = 0; i < max + 1; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < arrLength; ++i) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = arrLength - 1; i >= 0; --i) {
        arr[count[arr_copy[i]] - 1] = arr_copy[i];
        count[arr_copy[i]] = count[arr_copy[i]] - 1;
    }
}

int main() {
    long long n;
    cin >> n;
    long long* arr = new long long[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    counting_sort(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}

---------------------------------------------------SECOND SOLUTION---------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
template<class t>
void merge(t*arr1,int length1,t*arr2,int length2) {

    t* result = new t[length1 + length2];
    int cursor1 = 0; int cursor2 = 0; int rescursor = 0;

    while (cursor1 < length1 && cursor2 < length2) {
        if (arr1[cursor1] < arr2[cursor2]) {
            result[rescursor++] = arr1[cursor1++];
        }
        else {
            result[rescursor++] = arr2[cursor2++];
        }
    }

    while (cursor1<length1)
    {
        result[rescursor++] = arr1[cursor1++];
    }
    while (cursor2 < length2) {
        result[rescursor++] = arr2[cursor2++];
    }
    int finalLen = length1 + length2;
    for (int i = 0; i < finalLen; i++) {
        arr1[i] = result[i];
    }
    delete[]result;
}

template<class t>
void mergeSort(t*arr,int len) {
    
    if (len <= 1) { 
        return;
    }
    int mid = len / 2;
    mergeSort(arr, mid);
    mergeSort(arr+mid, len - mid);

    merge<t>(arr, mid, arr + mid, len - mid);

}

int main() {
    int n;
    cin>>n;
    
    int*arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr, n); 

    for (int i = n-1; i >=0; i--) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
