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
	node *root = new node(data);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
unordered_map<string, int> m;
vector<node*> v;
string duplicate(node*root) {
	if (root == NULL) {
		return "X";
	}
	string x = duplicate(root->left);
	string y = duplicate(root->right);
	string temp = to_string(root->data) + x + y;
	m[temp]++;
	if (m[temp] == 2) {
		v.push_back(root);
	}
	return temp;
}
void print(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
	cout << endl;
}
int main() {
	node*root = buildtree();
	duplicate(root);
	for (auto val : v) {
		print(val);
	}
}