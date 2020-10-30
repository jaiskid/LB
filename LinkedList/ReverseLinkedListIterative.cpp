#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};
node* createNode(node*&head, int data) {
	node *n = new node(data);
	n->next = head;
	head = n;
	return head;
}
void print(node*head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}o
}
void reverseLinkedlistUsingIterative(node*&head) {
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
int main() {
	node *head = NULL;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		head = createNode(head, data);
	}
	reverseLinkedlistUsingIterative(head);
	print(head);
}