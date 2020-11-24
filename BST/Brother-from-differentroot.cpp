#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};
unordered_set<int>s1, s2;
node* construct(node* root, int data) {
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
void preorder(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
void filltheset(node* root, unordered_set<int>&s) {
	if (root) {
		filltheset(root->left, s);
		s.insert(root->data);
		filltheset(root->right, s);
	}
}
int countPair(node*root1, node*root2, int x) {
	int sum = 0;
	for (auto ele : s1) {
		if (s2.find(x - ele) != s2.end()) {
			sum++;
		}
	}
	return sum;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	node*root1 = NULL, *root2 = NULL;
	while (n--) {
		int data;
		cin >> data;
		root1 = construct(root1, data);
	}
	while (m--) {
		int data;
		cin >> data;
		root2 = construct(root2, data);
	}

	filltheset(root1, s1);
	filltheset(root2, s2);
	int x;
	cin >> x;
	cout << countPair(root1, root2, x);
	return 0;
}