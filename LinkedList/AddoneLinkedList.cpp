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
void construct(node*&head, int data) {
	node*n = new node(data);
	n->next = head;
	head = n;
}
void print(node*head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void reverse(node*&head) {
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
	int n;
	cin >> n;
	node*head = NULL;
	while (n--) {
		int data;
		cin >> data;
		construct(head, data);
	}
	print(head);
	reverse(head);
	print(head);
}