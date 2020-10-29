#include<bits/stdc++.h>
using namespace std;
int sizeofarr(int *arr1, int n, int *arr2, int m) {
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n);
	int i = 0, j = 0;
	vector<int>ans;
	while (i < n && j < m) {
		if (arr1[i] < arr2[j]) {
			ans.push_back(arr1[i++]);
		}
		else if (arr1[i] > arr2[j]) {
			ans.push_back(arr2[j++]);
		}
		else {
			ans.push_back(arr2[j++]);
			i++;
		}
	}
	while (i < n) {
		ans.push_back(arr1[i++]);
	}
	while (j < m) {
		ans.push_back(arr2[j++]);
	}
	return ans.size();
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int m;
		cin >> m;
		int arr1[n];
		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
		}
		int arr2[m];
		for (int i = 0; i < m; i++) {
			cin >> arr2[i];
		}
		cout << sizeofarr(arr1, n, arr2, m) << endl;
	}
}