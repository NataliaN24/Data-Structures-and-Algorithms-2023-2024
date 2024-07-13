#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
  int N,K;
cin>>N>>K;
vector<int>arr(N);
for(int i=0;i<N;i++){
cin>>arr[i];
}
sort(arr.begin(),arr.end());
  
int smallestDifference=arr[K-1]-arr[0];
  
for(int i=1;i<=N-K;++i){                                     //this is done in order to itereate through each number of the array and to see if there are small differences between two numbers
int diff=arr[i+K-1]-arr[i];                     //for example if we have 1 2 3 4 10   K= 3 we calculate the difference 2 3 4 ,then 3 4 10 and if there is any smaller difference we update the difference we got above 
smallestDifference=min(smallestDifference,difference);     // if we dont do this part of code and we let the problem solved with smallestDifference between arr[k-1]-arr[0] not every case will be solved.
}
cout<<smallestDifference<<endl;
return 0;
}

//or sliding window------------------------------------------------------------------------------------------------------------similar to above------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> results(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> results[i];
    }

    std::sort(results.begin(), results.end());

    int minDifference = INT_MAX;

    for (int i = 0; i <= n - k; ++i) {
        int currentDifference = results[i + k - 1] - results[i];
        if (currentDifference < minDifference) {
            minDifference = currentDifference;
        }
    }

    std::cout << minDifference << std::endl;

    return 0;
}

