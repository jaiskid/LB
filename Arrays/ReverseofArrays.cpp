#include<bits/stdc++.h>
using namespace std;
void rotation(int *arr, int n) {
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		swap(arr[s++], arr[e--]);
	}
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	rotation(arr, n);
	for (auto val : arr) {
		cout << val << " ";
	}
}