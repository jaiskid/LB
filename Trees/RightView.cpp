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
void print(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}
void rightViewRecurr(node*root, int level, int &maxLevel) {
	if (root == NULL) {
		return;
	}
	if (maxLevel < level) {
		cout << root->data << " ";
	}
	rightViewRecurr(root->right, level + 1, maxLevel);
	rightViewRecurr(root->left, level + 1, maxLevel);
}
void rightView(node*root) {
	int maxLevel = 0;
	rightViewRecurr(root->right, 1, maxLevel);
}
int main() {
	node*root = buildtree();
	print(root);
	rightView(root);
}