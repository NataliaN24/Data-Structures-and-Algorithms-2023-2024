#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
-----------------------------------------FIRST SOLUTION-----------------------------------------------------------------------------------------------------------
int main() {
    int n, m;
    cin >> n;

    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int sum = 0;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            sum += arr1[i];
            i++;
            j++;
          
            while (i < n && arr1[i] == arr1[i - 1]) {
                i++;
            }
            while (j < m && arr2[j] == arr2[j - 1]) {
                j++;
            }
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout << sum << endl;

    return 0;
}
----------------------------------------------------SECOND SOLUTION----------------------------------------------------------------------------------------------
  #include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    set<int> uniqueNumbers; 

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        uniqueNumbers.insert(num); 
    }

    cin >> m;

    int sum = 0;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        
        if (uniqueNumbers.find(num) != uniqueNumbers.end()) {
            sum += num;
            uniqueNumbers.erase(num); 
        }
    }

    cout << sum;

    return 0;
}
