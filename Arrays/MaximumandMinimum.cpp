#include<bits/stdc++.h>
using namespace std;
int Maximum(int *arr, int n) {
	int res = INT_MIN;
	for (int i = 0; i < n; i++) {
		res = max(arr[i], res);
	}
	return res;
}
int Minimum(int*arr, int n) {
	int res = INT_MAX;
	for (int i = 0; i < n; i++) {
		res = min(arr[i], res);
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << Maximum(arr, n);
	cout << endl;
	cout << Minimum(arr, n);
}