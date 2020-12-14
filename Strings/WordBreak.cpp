#include<bits/stdc++.h>
using namespace std;
int wordBreak(string A, vector<string>&B) {
	int n = A.size();
	int dp[n + 1];
	memset(dp, 0, sizeof dp);
	dp[n] = 1;
	unordered_set<string> dict;
	for (string & val : B) {
		dict.insert(val);
	}
	
	for (int i = n - 1; i >= 0; i--) {
		string word;
		for (int j = i; j < n; j++) {
			word.push_back(A[j]);
			if (dict.find(word) != dict.end()) {
				if (dp[j + 1])
					dp[i] = 1;
			}
		}
	}
	return dp[0];
}
int main() {
	int n;
	cin >> n;
	vector<string> B;
	B.resize(n);
	for (int i = 0; i < B.size(); i++) {
		cin >> B[i];
	}
	string A;
	cin >> A;
	cout << wordBreak(A, B);
}