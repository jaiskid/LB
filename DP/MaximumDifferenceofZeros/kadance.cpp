#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int arr[s.size()];
	for (int i = 0; i < s.size(); i++) {
		arr[i] = (s[i] == '0') ? 1 : -1;
	}
	for (int i = 0; i < s.size(); i++) {
		cout << arr[i] << " ";
	}
	int cs = 0, ms = INT_MIN;
	for (int i = 0; i < s.size(); i++) {
		cs += arr[i];
		ms = max(ms, cs);
		if (cs < 0) {
			cs = 0;
		}
	}
	cout << ms;
}