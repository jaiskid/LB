#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left, *right;
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
void sumofLongRootToLeafPath(node*root, int sum, int len, int &maxLen, int &maxSum) {
	if (root == NULL) {
		if (maxLen < len) {
			maxLen = len;
			maxSum = sum;
		}
		else if (maxLen == len and maxSum < sum) {
			maxSum = sum;
		}
		return;
	}
	sumofLongRootToLeafPath(root->left, sum + root->data, len, maxLen, maxSum);
	sumofLongRootToLeafPath(root->right, sum + root->data, len, maxLen, maxSum);
}
int main() {
	node* root = buildtree();
	int maxLen = 0;
	int maxSum = INT_MIN;
	sumofLongRootToLeafPath(root, 0, 0, maxLen, maxSum);
	cout << maxSum;
}