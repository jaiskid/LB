#include<bits/stdc++.h>
using namespace std;
int firstOccurene(int *arr, int n, int key) {
	int ans = -1;
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (arr[mid] == key) {
			ans = mid;
			e = mid - 1;
		}
		else if (arr[mid] < key) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return ans;
}
int LastOccurene(int *arr, int n, int key) {
	int ans = -1;
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (arr[mid] == key) {
			ans = mid;
			s = mid + 1;
		}
		else if (arr[mid] < key) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return ans;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int key;
		cin >> key;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		if (firstOccurene(arr, n, key) != -1 and LastOccurene(arr, n, key) != -1)
			cout << firstOccurene(arr, n, key) << " " << LastOccurene(arr, n, key) << endl;
		else
			cout << -1 << endl;
	}

}