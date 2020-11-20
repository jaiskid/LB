#include<bits/stdc++.h>
using namespace std;
int peak(vector<int>&nums) {
	int s = 0;
	int e = nums.size() - 1;
	while (s < e) {
		int mid = s + (e - s) / 2;
		if (nums[mid] > nums[mid + 1]) {
			e = mid;
		}
		else {
			s = mid + 1;
		}
	}
	return s;
}
int main() {
	int n;
	cin >> n;
	vector<int>nums;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << peak(nums);
}