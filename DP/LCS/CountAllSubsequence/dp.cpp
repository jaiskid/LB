#include<bits/stdc++.h>
using namespace std;
int productSubSeqCount(vector<int>&arr, int k) {
	int n = arr.size();
	int dp[k + 1][n + 1];
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			// Number of subsequence using j - 1 terms
			dp[i][j] = dp[i][j - 1];
			// if arr[j-1] > i it will surely make product greater
			//thus it won't contribute then
			if (arr[j - 1] <= i and arr[j - 1] > 0) {
				dp[i][j] += dp[i / arr[j - 1]][j - 1] + 1;
			}
		}
	}
	return dp[k][n];
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int>arr;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int k;
	cin >> k;
	cout << productSubSeqCount(arr, k);
	return 0;
}