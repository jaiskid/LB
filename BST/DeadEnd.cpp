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
node*construct(node*root, int data) {
	if (root == NULL) {
		root = new node(data);
		return root;
	}
	if (data < root->data) {
		root->left = construct(root->left, data);
	}
	else {
		root->right = construct(root->right, data);
	}
	return root;
}
void inorder(node*root) {
	if (root ==  NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void traverse(node*root, bool &flag, int l, int r) {
	if (!flag || !root)
		return;
	if (l == r || r == 1) {
		flag = 0;
	}
	traverse(root->left, flag, l, root->data - 1);
	traverse(root->right, flag, root->data + 1, r);
}
bool isDeadEnd(node*root) {
	bool flag = 1;
	traverse(root, flag, INT_MIN, INT_MAX);
	return !flag;
}
int main() {
	node* root = NULL;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		root = construct(root, data);
	}
	inorder(root);
	cout << isDeadEnd(root);

}