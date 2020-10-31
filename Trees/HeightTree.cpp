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
int height(node*root) {
	if (root == NULL) {
		return 0;
	}
	return max(height(root->left), height(root->right)) + 1;
}
void print(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}
vector<int> LevelOrder(node*root) {
	queue<node*> q;
	q.push(root);
	vector<int> ans;
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		ans.push_back(temp->data);
		if (temp->left) {
			q.push(temp->left);
		}
		if (temp->right) {
			q.push(temp->right);
		}
	}
	return ans;
}
int main() {
	node* root = NULL;
	root = buildtree();
	print(root);
	cout << height(root);
}