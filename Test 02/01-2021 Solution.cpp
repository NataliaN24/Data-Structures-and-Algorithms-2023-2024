#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

int binarySearch(vector<int>& nums, int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int q;
    cin >> q;
    
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    int pivot = findPivot(nums);
    

    for (int i = 0; i < q; ++i) {
        int target = queries[i];
        int index;
        
        if (target >= nums[0]) {
     
            index = binarySearch(nums, target, 0, pivot - 1);
        } else {
           
            index = binarySearch(nums, target, pivot, n - 1);
        }
        
        cout << index << endl;
    }
    
    return 0;
}
