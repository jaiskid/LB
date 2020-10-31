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
void print(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}
int height(Node* root, int& ans) 
{ 
    if (root == NULL) 
        return 0; 
  
    int left_height = height(root->left, ans); 
  
    int right_height = height(root->right, ans); 
  
    // update the answer, because diameter of a 
    // tree is nothing but maximum value of 
    // (left_height + right_height + 1) for each node 
    ans = max(ans, 1 + left_height + right_height); 
  
    return 1 + max(left_height, right_height); 
} 
  
/* Computes the diameter of binary tree with given root. */
int diameterNew(Node* root) 
{ 
    if (root == NULL) 
        return 0; 
    int ans = INT_MIN; // This will store the final answer 
    int height_of_tree = height(root, ans); 
    return ans; 
} 
// int diameter(node*root) {
// 	if (root == NULL) {
// 		return 0;
// 	}
// 	int lheight = height(root->left);
// 	int rheight = height(root->right);
// 	int ldiameter = diameter(root->left);
// 	int rdiameter = diameter(root->right);
// 	return max(lheight + rheight + 1, max(ldiameter, rdiameter));
// }
int updateDiameterCON(node*root){
	int ans = INT_MIN;

}
int main() {
	node*root = NULL;
	root = buildtree();
	print(root);
	cout << height(root);
	cout << endl;
	cout << diameter(root);
}