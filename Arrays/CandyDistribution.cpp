#include<bits/stdc++.h>
using namespace std;
int Candies(int *arr, int n, int m) {
	sort(arr, arr + n);
	int diff = arr[m - 1] - arr[0];
	for (int i = m; i < n; i++) {
		diff = min(diff, arr[i] - arr[i - m + 1]);
	}
	return diff;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int m;
		cin >> m;
		cout << Candies(arr, n, m) << endl;
	}
	return 0;
}