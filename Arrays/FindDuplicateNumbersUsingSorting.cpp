#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>nums;
	nums.resize(n);
	for (int i = 0; i < nums.size(); i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	int ans;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == nums[i + 1]) {
			ans = nums[i];
			break;
		}
	}
	cout << ans << endl;
}