#include<bits/stdc++.h>
using namespace std;
int triplet(int *arr, int n, int sum) {
	int l, r;
	for (int i = 0; i < n - 2; i++) {
		l = i + 1;
		r = n - 1;
		while (l < r) {
			if (arr[i] + arr[l] + arr[r] == sum) {
				return true;
			}
			else if (arr[i] + arr[l] + arr[r] < sum) {
				l++;
			}
			else {
				r--;
			}
		}
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	int sum;
	cin >> sum;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);
	cout << triplet(arr, n, sum);
	return 0;

} 