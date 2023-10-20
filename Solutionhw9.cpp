#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool check(const vector<long long>& arr, long long  maxSum, long long  t) {
    long long  teams = 1;
    long long  currentSum = 0;

    for (long long skill : arr) {   //long long  skill : arr: This is a range-based for loop, which means that for each iteration, the variable skill takes on the value of the next element in the developers vector.
        if (currentSum + skill > maxSum) {
            teams++;
            currentSum = 0;
        }
         currentSum += skill;
    }
    return teams <= t;

}
//if (currentSum + skill > maxSum): Inside the loop, there's an if statement that checks whether adding the current developer's skill to the currentSum would exceed the maxSum. In other words, it checks if including this developer's skill in the current team would make the team's skill sum go over the maximum allowed (maxSum).

//teams++; currentSum = 0;: If adding the current skill to currentSum exceeds maxSum, it means a new team should be formed. Therefore, teams (the count of teams) is incremented, and currentSum is reset to 0 because this developer starts a new team.

//currentSum += skill: Regardless of whether a new team is formed, the developer's skill is added to the currentSum. This keeps track of the total skill sum for the current team

long long binarySearch(const vector<long long>& arr, long long  n, long long  t, long long  right,long long left) {
    
    while (left < right) {
        long long mid = left +(right - left) / 2;
        if (check(arr, mid, t)) {
            
            right = mid ;
        }
        else {
            left = mid + 1;
        }
    }
    return  left;

}

int main() {
    long long  n;
    long long  t;
    cin >> n >> t;
    vector<long long>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
   
    long long left = 0;
    long long right = 0;
    for (int i = 0; i < n; i++) {
        right += arr[i];
        left = max(left, arr[i]);
    }

    cout << binarySearch(arr, n, t, right,left);

}

