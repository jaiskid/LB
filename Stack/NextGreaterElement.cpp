#include<bits/stdc++.h>
using namespace std;
vector<int> nge(vector<int>nums) {
	stack<int> s;
	vector<int> ans;
	s.push(nums[nums.size() - 1]);
	ans.push_back(-1);
	for (int i = nums.size() - 2; i >= 0; i--) {
		while (!s.empty() and nums[i] >= s.top()) {
			s.pop();
		}
		if (s.size() == 0) {
			ans.push_back(-1);
		}
		else {
			ans.push_back(s.top());
		}
		s.push(nums[i]);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<int>nums;
	nums.resize(n);
	for (int i = 0; i < nums.size(); i++) {
		cin >> nums[i];
	}
	auto ans = nge(nums);
	for (auto val : ans) {
		cout << val << " ";
	}
}