#include<bits/stdc++.h>
using namespace std;
int duplicateNumbers(vector<int>&nums, int n) {
	set<int>s;
	int ans;
	for (int i = 0; i < n; i++) {
		if (s.find(nums[i]) == s.end()) {
			s.insert(nums[i]);
		}
		else {
			ans = nums[i];
			break;
		}
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<int>nums;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << duplicateNumbers(nums, n);
}