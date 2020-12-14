#include<bits/stdc++.h>
using namespace std;
void reverse(string &s) {
	int i =  0;
	int j =  s.size() - 1;
	while (i < j) {
		swap(s[i], s[j]);
		i++;
		j--;
	}
	return;
}
int main() {
	string s;
	cin >> s;
	reverse(s);
	cout << s;
}