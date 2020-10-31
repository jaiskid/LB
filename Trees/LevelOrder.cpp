#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node*left, *right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};
node* buildtree() {
	int data;
	cin >> data;
	if (data == -1)
		return NULL;
	node*root = new node(data);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
vector<int> levelorder(node*root) {
	//Use queue for level order
	queue<node*>q;
	vector<int> v;
	q.push(root);
	while (!q.empty()) {
		node*temp = q.front();
		q.pop();
		v.push_back(temp->data);
		if (temp->left) {
			q.push(root->left);
		}
		if (temp->right) {
			q.push(root->right);
		}
	}
	return v;
}
void print(node* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}
int main() {
	node*root = NULL;
	root = buildtree();
	// print(root);
	auto val = levelorder(root);
	for (auto v : val) {
		cout << v << " ";
	}
}