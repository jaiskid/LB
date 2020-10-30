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
void RemoveDuplicate(node*&head) {
	node*curr = head;
	node*res;
	if (curr == NULL)
		return;
	while (curr->next != NULL) {
		if (curr->data == curr->next->data) {
			res = curr->next->next;
			free(curr->next);
			curr->next = res;
		}
		else {
			curr = curr->next;
		}

	}
}
void print(node*head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}
int main() {
	node* head = NULL;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		construct(head, data);
	}
	// print(head);
	RemoveDuplicate(head);
	print(head);
}