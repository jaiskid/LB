#include<bits/stdc++.h>
using namespace std;
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1};
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1};
#define r 3
#define c 13
bool patternSearchgrid(char grid[r][c], int row, int col, string word) {
	if (grid[row][col] != word[0]) {
		return false;
	}
	int len = word.length();
	for (int dir = 0 ; dir < 8; dir++) {
		int k, rd = row + x[dir], cd = col + y[dir];
		for (k = 1; k < len; k++) {
			if (rd >= r || rd < 0 || cd >= c || cd < 0)
				break;
			if (grid[rd][cd] != word[k])
				break;
			rd += x[dir], cd += y[dir];
		}
		if (k == len) {
			return true;
		}
	}
	return false;
}
int main() {
	char grid[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}
	string word;
	cin >> word;

	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++) {
			if (patternSearchgrid(grid, row, col, word)) {
				cout << "Pattern found at " << row << ", " << col << endl;
			}
		}
	}

}