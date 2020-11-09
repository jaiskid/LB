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

vector<node*>v;
string preorder(node* root, unordered_map<string, int> &mp)
{
	string s;
	if (!root)
	{
		s += "X";
		return s;
	}
	s += root->data;
	s += preorder(root->left, mp);
	s += preorder(root->right, mp);
	mp[s]++;
	if (mp[s] == 2) {
		v.push_back(root);
	}
	return s;
}
// bool dupSub(Node *root)
// {
// for(auto i:mp)
//  if(i.second>=2&&i.first.length()>3)
//     return true;
//   return false;
// }
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
	unordered_map<string, int> mp;
	preorder(root, mp);
	for (auto x : mp) {
		cout << x.first << " " << x.second << endl;
	}
	cout << endl;
	for (auto val : v) {
		print(val);
	}
}