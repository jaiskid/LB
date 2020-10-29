#include<bits/stdc++.h>
using namespace std;
  vector <int> commonElements (int a[], int b[], int c[], int m, int n, int o)
{
	vector<int> res;
	//code here.
	int i = 0, j = 0, k = 0;
	while (i < m and j < n and k < o) {
		if (a[i] == b[j] and b[j] == c[k]) {
			res.push_back(a[i]);
			i++;
			j++;
			k++;
		}
		else if (a[i] < b[j]) {
			i++;
		}
		else if (b[j] < c[k]) {
			j++;
		}
		else {
			k++;
		}
	}
	
	set<int> s;
    for(auto val : res){
        s.insert(val);
    }
    res.clear();
    for(auto val : s){
        res.push_back(val);
    }
    return res;
}
int main() {
	int m;
	cin >> m;
	int a[m];
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	int n;
	cin >> n;
	int b[n];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int o;
	cin >> o;
	int c[o];
	for (int i = 0; i < o; i++) {
		cin >> c[i];
	}
	vector<int>ans = commonElements(a, b, c, m, n, o);
	for (auto val : ans) {
		cout << val << " ";
	}
}