#include<bits/stdc++.h>
using namespace std;
int smallestSubwithsum(int *arr, int n, int x) {
	int min_len = n + 1;
	for (int start = 0; start < n; start++) {
		int curr_sum = arr[start];
		if (curr_sum > x)
			return 1;
		for (int end = start + 1; end < n; end++) {
			curr_sum += arr[end];
			if (curr_sum > x and (end - start + 1) < min_len)
				min_len = (end - start + 1);
		}
	}
	return min_len;
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x;
	cin >> x;
	cout << smallestSubwithsum(arr, n, x);
}