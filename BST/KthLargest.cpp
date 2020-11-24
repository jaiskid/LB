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
void ReverseInorder(node*root, int k, int &index, int &res) {
	if (root != NULL) {
		ReverseInorder(root->right, k, index, res);
		if (index == k) {
			res = root->data;
		}
		index++;
		ReverseInorder(root->left, k, index, res);
	}
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

	int k;
	cin >> k;
	int index = 1;
	int res = -1;
	ReverseInorder(root, k, index, res);
	cout << res << endl;
}