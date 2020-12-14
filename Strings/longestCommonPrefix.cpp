#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<string> res;
	res.resize(n);
	for (int i = 0; i < res.size(); i++) {
		cin >> res[i];
	}
	sort(res.begin(), res.end());
	string a = res[0];
	string b = res[n - 1];
	int i = 0;
	while (a[i] != '\0' and b[i] != '\0') {
		if (a[i] == b[i]) {
			cout << a[i];
		}
		else
			break;
		i++;
	}
}