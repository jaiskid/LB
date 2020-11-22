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
node* binaryconstruct() {
	int data;
	cin >> data;
	if (data == -1)
		return NULL;
	node* root = new node(data);
	root->left = binaryconstruct();
	root->right = binaryconstruct();
	return root;
}
void preorder(node*root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(node*root, vector<int>&in) {
	if (root == NULL)
		return;
	inorder(root->left, in);
	in.push_back(root->data);
	inorder(root->right, in);
}
void bst(node*root, vector<int>&in, int &i) {
	if (root == NULL)
		return;
	bst(root->left, in, i);
	root->data = in[i++];
	bst(root->right, in, i);
}
node*construct(node*root) {
	vector<int>in;
	inorder(root, in);
	sort(in.begin(), in.end());
	int i = 0;
	bst(root, in, i);
	return root;
}
void inorder(node*root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
int main() {
	node*root = NULL;
	root = binaryconstruct();
	// preorder(root);
	cout << endl;
	root = construct(root);
	inorder(root);
}