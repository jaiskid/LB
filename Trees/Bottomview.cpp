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
void bottomup(node*root) {
	map<int, int> m;
	queue<pair<node*, int>>q;
	q.push(make_pair(root, 0));
	while (!q.empty()) {
		pair<node*, int> curr = q.front();
		q.pop();
		m[curr.second] = curr.first->data;
		if (curr.first->left) {
			q.push(make_pair(curr.first->left, curr.second - 1));
		}
		if (curr.first->right) {
			q.push(make_pair(curr.first->right, curr.second + 1));
		}
	}
	for (auto val : m) {
		cout << val.second << " ";
	}
}
int main() {
	node*root = buildtree();
	bottomup(root);
}