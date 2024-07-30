#include<iostream>
#include<vector>

Given an array of integers numsand an integer target, return indices of the two numbers such that they add up to target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//You can return the answer in any order.
//
//
//
//Example 1:
//
//Input: nums = [2, 7, 11, 15], target = 9
//Output : [0, 1]
//Explanation : Because nums[0] + nums[1] == 9, we return[0, 1].
//Example 2 :
//
//	Input : nums = [3, 2, 4], target = 6
//	Output : [1, 2]
//	Example 3 :
//
//	Input : nums = [3, 3], target = 6
//	Output : [0, 1]
//
//
//	Constraints :
//
//	2 <= nums.length <= 104
//	- 109 <= nums[i] <= 109
//	- 109 <= target <= 109
//	Only one valid answer exists.


//My solution

using namespace std;
int main() {
	int n, k;

	cin >> n >> k;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == k) {
				cout << i << j;
				break;
			}
		}
	}
}

//Teacher's solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        vector<pair<int, int>> newArr;
        for(int i=0;i<N;++i) {
            newArr.push_back({nums[i], i});
        }
        sort(newArr.begin(), newArr.end());
        for (int i = 0, j = N - 1; i < j; i++) {
            while (i < j && newArr[i].first + newArr[j].first > target)
                j--;
            if (i < j && newArr[i].first + newArr[j].first == target)
                return vector<int>{newArr[i].second, newArr[j].second};     //initializes new vector to return
        }
        // It is guaranteed that there will be an answer for every test, so
        // this return is just for the compiler to not emit errors.
        return nums;
    }
};
