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
	node * root = new node(data);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
void printKPathutil(node*root, vector<int>&path, int k) {
	if (root == NULL) {
		return;
	}
	path.push_back(root->data);
	printKPathutil(root->left, path, k);
	printKPathutil(root->right, path, k);
	int f = 0;
	for (int j = path.size() - 1; j >= 0; j--) {
		f += path[j];
		if (f == k) {
			for (int i = j; i < path.size(); i++) {
				cout << path[i] << " ";
			}
			cout << endl;
		}
	}
	path.pop_back();
}
int main() {
	node*root = buildtree();
	int k;
	cin >> k;
	vector<int>path;
	printKPathutil(root, path, k);
}