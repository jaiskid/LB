#include<bits/stdc++.h>
using namespace std;
int vis[100][100];
int path = 0;
void go(vector<vector<int>>&v, int sx, int sy, int dx, int dy, int r, int c) {
	if (sx<0 or sy<0 or sx >= r or sy >= c or v[sx][sy] == 0 or vis[sx][sy] == 1) {
		return;
	}
	if (sx == dx and sy == dy)
		path += 1;
	vis[sx][sy] = 1;
	go(v, sx, sy - 1, dx, dy, r, c);
	go(v, sx, sy + 1, dx, dy, r, c);
	go(v, sx - 1, sy, dx, dy, r, c);
	go(v, sx + 1, sy, dx, dy, r, c);
	vis[sx][sy] = 0;
}
int main() {
	int r, c;
	cin >> r >> c;
	vector<vector<int>>v(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> v[i][j];
		}
	}
	memset(vis, 0, sizeof(vis));
	go(v, 0, 0, r - 1, c - 1, r, c);
	cout << path;
}