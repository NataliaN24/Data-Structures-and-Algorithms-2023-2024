#include<iostream>
#include<vector>
//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
using namespace std;
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
