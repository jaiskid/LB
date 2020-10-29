#include<bits/stdc++.h>
using namespace std;
int sizeofarr(int *arr1, int n, int *arr2, int m) {
	set<int>s;
	for (int i = 0; i < n; i++) {
		s.insert(arr1[i]);
	}
	for (int i = 0; i < m; i++) {
		s.insert(arr2[i]);
	}
	return s.size();
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