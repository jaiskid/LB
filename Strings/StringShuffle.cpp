#include<bits/stdc++.h>
using namespace std;
bool shuffleCheck(string a, string b, string checker) {
	if (a.size() + b.size() != checker.size()) {
		return false;
	}
	int i = 0, j = 0, k = 0;
	while (k != checker.size()) {
		if (i < a.size() && a[i] == checker[k])
			i++;
		else if (j < b.size() && b[j] == checker[k])
			j++;
		else
			return false;
		k++;
	}
	// after accessing all characters of result
	// if either first or second has some characters left
	if (i < a.size() || j < b.size()) {
		return false;
	}
	return true;
}
int main() {
	string a, b;
	cin >> a >> b;
	string checker;
	cin >> checker;
	if (shuffleCheck(a, b, checker) == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}