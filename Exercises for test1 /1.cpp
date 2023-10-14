#include<iostream>
#include<vector>
//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
//Note that you must do this in - place without making a copy of the array.
//
//
//
//Example 1:
//
//Input: nums = [0, 1, 0, 3, 12]
//Output : [1, 3, 12, 0, 0]
//Example 2 :
//
//	Input : nums = [0]
//	Output : [0]

using namespace std;

//My solution
int main() {
	int n;
	cin >> n;
	vector<int>oldvector(n);
	for (int i = 0; i < n; i++) {
		cin >> oldvector[i];
	}
	vector<int>newvector(n);
	int j = 0; int counter = 0;
	for (int i = 0; i < n; i++) {
		if (oldvector[i] != 0) {
			newvector[j] = oldvector[i];
			j++;
		}
		else {
			counter++;
		}
	}


	for (int i = n - counter; i < n; i++) {
		newvector[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		cout << newvector[i] << " ";
	}
}

//Solution from teaching assistant
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int br = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] != 0) {
                swap(nums[i], nums[br++]);
            }
        }
    }
};

