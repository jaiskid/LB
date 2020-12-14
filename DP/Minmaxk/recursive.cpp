#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int countRemovals(int *arr, int i, int j, int k) {
	if (i >= j) {
		return 0;
	}
	else if ((arr[j] - arr[i]) <= k) {
		return 0;
	}
	else if (dp[i][j] != -1) {
		return dp[i][j];
	}
	else if ((arr[j] - arr[i] ) > k) {
		dp[i][j] = 1 + min(countRemovals(arr, i + 1, j, k), countRemovals(arr, i, j - 1, k));
	}
	return dp[i][j];
}
int removals(int *arr, int n, int k) {
	memset(dp, -1, sizeof dp);
	if (n == 1)
		return 0;
	else
		return countRemovals(arr, 0, n - 1, k);
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int k;
	cin >> k;
	sort(arr, arr + n);
	cout << removals(arr, n, k);
}