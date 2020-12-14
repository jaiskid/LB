#include<bits/stdc++.h>
using namespace std;
string secFrequent(string* arr, int n) {
	unordered_map<string, int> mp;
	string s = "";
	for (int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}
	int max1 = INT_MIN;
	int max2 = INT_MIN;
	for (auto i : mp) {
		max1 = max(max1, i.second);
	}
	for (auto i : mp) {
		if (i.second != max1) {
			max2 = max(max2, i.second);
		}
	}
	for (auto i : mp) {
		if (i.second == max2) {
			s = i.first;
			break;
		}
	}
	return s;
}
int main() {
	int n;
	cin >> n;
	string arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << secFrequent(arr, n);
}