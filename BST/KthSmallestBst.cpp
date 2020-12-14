#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node*left;
	node*right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};
node* construct(node*root, int data) {
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
void inorder(node*root, int k, int &index, int &res) {
	if (root != NULL) {
		inorder(root->left, k, index, res);
		if (index == k) {
			res = root->data;
		}
		index++;
		inorder(root->right, k, index, res);
	}

}
void preorder(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main() {
	node*root = NULL;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		root = construct(root, data);
	}
	preorder(root);
	int k;
	cin >> k;
	int res = -1;
	int index = 1;
	inorder(root, k, index, res);
	cout << res;
}