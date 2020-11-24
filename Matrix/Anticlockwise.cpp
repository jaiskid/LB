#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<vector<int>> nums(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> nums[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n / 2; j++) {
			swap(nums[i][j], nums[i][n - j - 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			swap(nums[i][j], nums[j][i]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
}