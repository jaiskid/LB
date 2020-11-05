#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node*left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};
node* buildtree() {
	int data;
	cin >> data;
	if (data == -1) {
		return NULL;
	}
	node*root = new node(data);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
void diagonalPrintUntil(node*root, int d, map<int, vector<int>>&diagonalPrint) {
	if (!root) {
		return;
	}
	diagonalPrint[d].push_back(root->data);
	diagonalPrintUntil(root->left, d + 1, diagonalPrint);
	diagonalPrintUntil(root->right, d, diagonalPrint);
}
void diagonal(node*root) {
	map<int, vector<int>> diagonalPrint;
	diagonalPrintUntil(root, 0, diagonalPrint);
	for (auto val : diagonalPrint) {
		auto v = val.second;
		for (auto it : v) {
			cout << it << " ";
		}
		cout << endl;
	}
}
int main() {
	node*root = buildtree();
	diagonal(root);
}