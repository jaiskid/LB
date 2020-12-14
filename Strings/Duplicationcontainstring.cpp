#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	unordered_map<char, int>mp;
	for (auto val : s) {
		mp[val]++;
	}
	for (auto val : mp) {
		if (val.second >= 2)
			cout << val.first << " ";
	}
	return 0;
}