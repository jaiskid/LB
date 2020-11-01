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
	node* root = new node(data);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
void print(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}
void getVerticalOrder(node*root, int hd, map<int, vector<int>>&m) {
	if (root == NULL) {
		return;
	}
	m[hd].push_back(root->data);
	getVerticalOrder(root->left, hd - 1, m);
	getVerticalOrder(root->right, hd + 1, m);
}
void printVerticalOrder(node* root) {
	map<int, vector<int>>m;
	int hd = 0;
	getVerticalOrder(root, hd, m);
	// Traverse the map and print nodes at every horigontal
	// distance (hd)
	map< int, vector<int> > :: iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		for (int i = 0; i < it->second.size(); ++i)
			cout << it->second[i] << " ";
		cout << endl;
	}
}
int main() {
	node*root = buildtree();
	printVerticalOrder(root);
}