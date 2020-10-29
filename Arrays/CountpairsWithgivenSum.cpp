#include<bits/stdc++.h>
using namespace std;
int Pairs(int* arr, int n, int k) {
	unordered_map<int, int> mp;
	for (int i = 0; i < n; ++i)
	{
		mp[arr[i]]++;
	}
	// for (auto val : mp) {
	// 	cout << val.first << " " << val.second << endl;
	// }
	int twice_count = 0;
	for (int i = 0; i < n; i++) {
		twice_count += mp[k - arr[i]];
		if (k - arr[i] == arr[i]) {
			twice_count--;
		}
	}
	return twice_count / 2;
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
	cout << Pairs(arr, n, k);
}