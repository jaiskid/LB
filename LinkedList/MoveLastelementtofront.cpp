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
}
void mover(node*&head) {
	if (head == NULL || head->next == NULL) {
		return;
	}
	node*secLast = NULL;
	node*last = head;
	while (last->next != NULL) {
		secLast = last;
		last = last->next;
	}
	secLast->next = NULL;
	//creating null after n-1 nodes
	// attaching head to the last node
	last->next = head;
	// print(last);
	//New head updated
	head = last;
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
	mover(head);
}