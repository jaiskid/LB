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
bool ans;
int height(node*root) {
	if (root == NULL) {
		return 0;
	}
	int left = height(root->left);
	int right = height(root->right);
	if (root->left and root->right and left != right)
		ans = false;
	return 1 + max(left, right);
}
int main() {
	node*root = buildtree();
	ans = true;
	cout << height(root);
	cout << endl << ans;
}