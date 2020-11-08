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
node* buildtree()
{
	int data;
	cin >> data;
	if (data == -1) {
		return NULL;
	}
	node *root = new node(data);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}

void printAllpathsfromroot(node*root, int sum, int sum_so_far, vector<int>&path) {
	if (root == NULL) {
		return;
	}
	sum_so_far += root->data;
	path.push_back(root->data);
	if (sum_so_far == sum) {
		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << " ";
		}
		cout << endl;
	}
	if (root->left != NULL) {
		printAllpathsfromroot(root->left, sum, sum_so_far, path);
	}
	if (root->right != NULL) {
		printAllpathsfromroot(root->right, sum, sum_so_far, path);
	}
	path.pop_back();
}
int main() {
	node*root = buildtree();
	vector<int>path;
	int sum;
	cin >> sum;
	printAllpathsfromroot(root, sum, 0, path);
}