Подредете в намаляващ ред подаденият масив.
//
//За тази задача не се позволява използването на вградени функции за сортиране.
//
//Input Format
//
//N - брой на елементите на масива X1 X2 ... XN - елементите на масива разделени с интервал
//
//Constraints
//
//N - ще нараства във всеки тест, като ще стигне до 10, 000, 000
//
//0 < Х_i < 100, 000
//
//	Output Format
//
//	сортираните елементи на масива във низходящ ред, разделени с интервал
//
//	Sample Input 0
//
//	10
//	9 2 6 8 9 9 8 0 3 9
//	Sample Output 0
//
//	9 9 9 9 8 8 6 3 2 0
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



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
