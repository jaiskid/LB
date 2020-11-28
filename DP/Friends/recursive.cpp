#include<bits/stdc++.h>
using namespace std;
int friendsPairing(int n) {
	if (n <= 2)
		return n;
	else
		return friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << friendsPairing(n);
	return 0;
}