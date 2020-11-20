#include<bits/stdc++.h>
using namespace std;
int minimumelement(vector<int>&nums) {
	int s = 0;
	int e = nums.size() - 1;
	while (s < e) {
		int mid = s + (e - s) / 2;
		if (nums[mid] < nums[e]) {
			e = mid;
		}
		else {
			s = mid + 1;
		}
	}
	return nums[s];
}
int main() {
	int n;
	cin >> n;
	vector<int>nums;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << minimumelement(nums);
}