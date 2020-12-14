#include<bits/stdc++.h>
using namespace std;
bool isrotations(string a, string b) {
	if (a.size() != b.size())
		return false;
	string temp = a + b;
	return (temp.find(b) != string::npos);
}
int main() {
	string a;
	cin >> a;
	string b;
	cin >> b;
	(isrotations(a, b)) ? cout << "Yes" : cout << "No";

}