За тази задача не се позволява използването на вградени функции и структури от данни за сортиране!
//
//В Youtube решили да намерят колко видове различни видеа имат в платформата, като за целта използвали 
//алгоритъм, който асоциира със всяко видео число, а в последствие всички тези числа поставили в масив 
//и почнали да питат кандидати за интервю как биха изкарали в сортирана последователност всички различни числа.Решете задачата и вие : )
//
//
//
//	Sample Input 0
//
//	10
//	2 6 4 0 3 9 9 9 6 0
//	Sample Output 0
//
//	0 2 3 4 6 9

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
