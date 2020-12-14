#include<bits/stdc++.h>
using namespace std;
int minJumps(int *arr, int n) {
	int dp[n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int temp = arr[i];
		int j = i + 1;
		while (j < n and temp--) {
			dp[j] = min(dp[j], dp[i] + 1);
			j++;
		}
	}
	if (dp[n - 1] < 0 || dp[n - 1] == INT_MAX)
		return -1;
	return dp[n - 1];
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << minJumps(arr, n);
}