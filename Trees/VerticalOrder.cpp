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
void print(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}
void printVerticalOrder(node* root)
{
	// Base case
	if (!root)
		return;

	// Create a map and store vertical oder in
	// map using function getVerticalOrder()
	map<int, vector<int> > m;
	int hd = 0;

	// Create queue to do level order traversal.
	// Every item of queue contains node and
	// horizontal distance.
	queue<pair<node*, int> > que;
	que.push(make_pair(root, hd));

	while (!que.empty()) {
		// pop from queue front
		pair<node*, int> temp = que.front();
		que.pop();
		hd = temp.second;
		node* node = temp.first;

		// insert this node's data in vector of hash
		m[hd].push_back(node->data);

		if (node->left != NULL)
			que.push(make_pair(node->left, hd - 1));
		if (node->right != NULL)
			que.push(make_pair(node->right, hd + 1));
	}

	// Traverse the map and print nodes at
	// every horigontal distance (hd)
	map<int, vector<int> >::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		for (int i = 0; i < it->second.size(); ++i)
			cout << it->second[i] << " ";
		cout << endl;
	}
}
int main() {
	node* root = buildtree();
	printVerticalOrder(root);
}