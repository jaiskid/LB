#include<bits/stdc++.h>
using namespace std;
int getMinHeight(int *arr, int n, int k) {
	sort(arr, arr + n);
	int s = 0;
	int e = n - 1;
	int mid = s + (e - s) / 2;
	for (int i = 0; i < mid; i++) {
		arr[i] = arr[i] + k;
	}
	for (int i = mid + 1; i < n; i++) {
		arr[i] = arr[i] - k;
	}
	return arr[n - 1] - arr[0];
}
int main() {
	int k;
	cin >> k;
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << getMinHeight(arr, n, k);
}
