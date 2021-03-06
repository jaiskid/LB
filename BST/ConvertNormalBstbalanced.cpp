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
void inorder(node*root, vector<node*>&in) {
	if (root == NULL)
		return;
	inorder(root->left, in);
	in.push_back(root);
	inorder(root->right, in);
}
node*buildtree(vector<node*>&in, int start, int end) {
	if (start > end)
		return NULL;
	int mid = start + (end - start) / 2;
	node*root = in[mid];
	root->left = buildtree(in, start, mid - 1);
	root->right = buildtree(in, mid + 1, end);
	return root;
}
void preorder(node*root) {
	if (root == NULL)
		return;
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
	vector<node*>in;
	cout << endl;
	inorder(root, in);
	root = buildtree(in, 0, in.size() - 1);
	preorder(root);
}