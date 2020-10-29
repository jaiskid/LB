#include<bits/stdc++.h>
using namespace std;
bool finder(int *arr, int n) {
	unordered_set<int> set;
	set.insert(0);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (set.find(sum) != set.end()) {
			return true;
		}
		else {
			set.insert(sum);
		}
	}
	return false;
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
		(finder(arr, n)) ? cout << "YES" << endl : cout << "NO" << endl;
	}

}