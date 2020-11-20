#include<bits/stdc++.h>
using namespace std;
multiset<string> res;
string temp = "";
void go(string s, int pos) {
	res.insert(temp);
	for (int i = pos; i < s.size(); i++) {
		temp.push_back(s[i]);
		go(s, i + 1);
		temp.pop_back();
	}
}
int main() {
	string s;
	cin >> s;
	go(s, 0);
	for (auto i : res) {
		cout << i << endl;
	}
}