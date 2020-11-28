#include<bits/stdc++.h>
using namespace std;
bool sumtarget(int *arr, int sum, int n) {
	if (sum == 0) {
		return true;
	}
	if (sum != 0 and n == 0) {
		return false;
	}
	if (arr[n - 1] > sum)
		return sumtarget(arr, sum, n - 1);
	if (arr[n - 1] <= sum)
		return sumtarget(arr, sum - arr[n - 1], n - 1) || sumtarget(arr, sum, n - 1);
}
bool sumpartition(int *arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	if (sum % 2 != 0)
		return false;
	return sumtarget(arr, sum / 2, n);
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (sumpartition(arr, n)){
		cout<<"Yes";
	}
	else
		cout<<"NO";
}