#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	unordered_map<char, int> mp;
	mp['I'] = 1;
	mp['V'] = 5;
	mp['X'] = 10;
	mp['L'] = 50;
	mp['C'] = 100;
	mp['D'] = 500;
	mp['M'] = 1000;
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i + 1 < s.size() and mp[s[i]] < mp[s[i + 1]]) {
			res += mp[s[i + 1]] - mp[s[i]];
			i += 1;
		}
		else
			res += mp[s[i]];
	}
	cout << res;
}