#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node*next;
	node(int d) {
		data = d;
		next = NULL;
	}
};
void CreateList(node*&head, int data) {
	node *n = new node(data);
	n->next = head;
	head = n;
	// return head;
}
void print(node*head) {
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}
void reverseIterative(node*&head) {
	node*curr = head;
	node*prev = NULL;
	node*save;
	while (curr) {
		save = curr->next;
		curr->next = prev;
		prev = curr;
		curr = save;
	}
	head = prev;
}
void Recursive(node*prev, node*curr, node*&head) {
	if (!curr)
		return;
	if (!curr->next) {
		head = curr;
		curr->next = prev;
		return;
	}
	Recursive(curr, curr->next, head);
	curr->next = prev;
}
node* reverseinK(node*&head, int k) {
	node*curr = head;
	node*prev = NULL;
	node*save = NULL;
	int count = 0;
	while (curr != NULL and count < k) {
		save = curr->next;
		curr->next = prev;
		prev = curr;
		curr = save;
		count++;
	}
	if (save != NULL)
		head->next = reverseinK(save, k);
	return prev;
}
int main() {
	node*head = NULL;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		CreateList(head, data);
	}
	// reverseIterative(head);
	 print(head);
	// cout << endl;
	// Recursive(NULL, head, head);
	// print(head);
	cout << endl;
	head = reverseinK(head, 3);
	print(head);
}