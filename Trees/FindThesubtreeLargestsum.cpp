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
int findTheSubtree(node*root, int &ans) {
	if (root == NULL) {
		return 0;
	}
	int currsum = root->data + findTheSubtree(root->left, ans) + findTheSubtree(root->right, ans);
	ans = max(currsum, ans);
	return currsum;
}
int main() {
	node*root = buildtree();
	int ans = INT_MIN;
	cout << findTheSubtree(root, ans);
	cout << ans;
}