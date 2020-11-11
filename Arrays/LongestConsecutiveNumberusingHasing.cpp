#include<bits/stdc++.h>
using namespace std;
int findLength(unordered_map<int, int> mp, int key) {
	int ans = 0;
	while (mp.find(key) != mp.end()) {
		ans++;
		key++;
	}
	return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp.insert({arr[i], 1});
	}
	for (auto val : mp) {
		cout << val.first << " " << val.second << endl;
	}
	for (int i = 0; i < n; i++) {
		if (mp.find(arr[i] - 1) != mp.end()) {
			mp[arr[i]] = 0;
		}
	}
	for (auto val : mp) {
		cout << val.first << " " << val.second << endl;
	}
	int maximum = 0;
	for (auto key : mp) {
		if (mp.find(key.first) != mp.end()) {
			maximum = max(maximum, findLength(mp, key.first));
		}
	}
	cout << maximum << endl;
	}
	
	return 0;
}