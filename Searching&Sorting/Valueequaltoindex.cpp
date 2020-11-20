#include<bits/stdc++.h>
using namespace std;
vector<int> valueEqualToIndex(int arr[], int n) {
	// code here
	vector<int>ans;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == i) {

			ans.push_back(i);
		}
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	// for (int i = 1; i <= n; i++) {
	// 	if (arr[i] == i) {
	// 		cout << i;
	// 	}
	// }
	vector<int> ans = valueEqualToIndex(arr, n);
	for (auto val : ans) {
		cout << val << endl;
	}
	return 0;
}