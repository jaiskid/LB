#include<bits/stdc++.h>
using namespace std;
int Count(string s) {
	int zero = 0;
	int one = 0;
	int cnt = 0;
	for (auto val : s) {
		if (val == '0')
			zero++;
		else if (val == '1')
			one++;
		if (zero == one)
			cnt++;
	}
	if (one != zero)
		return -1;
	return cnt;
}
int main() {
	string s;
	cin >> s;
	cout << Count(s);
}