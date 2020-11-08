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
int sumOfgrandChildren(node*root, map<node*, int>&mp);
int getMaxSumUtil(node*root, map<node*, int>&mp);
int sumOfgrandChildren(node*root, map<node*, int>&mp) {
	int sum = 0;
	if (root->left) {
		sum += getMaxSumUtil(root->left->left, mp) + getMaxSumUtil(root->left->right, mp);
	}
	if (root->right) {
		sum += getMaxSumUtil(root->right->right, mp) + getMaxSumUtil(root->right->left, mp);
	}
	return sum;
}
int getMaxSumUtil(node* root , map<node*, int>&mp) {
	if (root == NULL) {
		return 0;
	}
	if (mp.find(root) != mp.end()) {
		return mp[root];
	}
	int incl = root->data + sumOfgrandChildren(root, mp);
	int excl = getMaxSumUtil(root->left, mp) + getMaxSumUtil(root->right, mp);
	mp[root] = max(incl, excl);

	return mp[root];
}


int main() {
	node*root = buildtree();
	map<node*, int> mp;
	cout << getMaxSumUtil(root, mp);
}