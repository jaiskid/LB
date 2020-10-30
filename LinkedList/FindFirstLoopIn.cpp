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
	node* n = new node(data);
	n->next = head;
	head = n;
}
node* detect(node*head) {
	node*slow = head;
	node* fast = head;
	while (slow and fast and fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return slow;
		}
	}
	return NULL;
}
node* removeLoop(node*head) {
	node*slow = head;
	node*fast = head;
	slow = slow->next;
	fast = fast->next->next;
	while (fast and fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			break;
		}
	}
	if (slow != fast) {
		return NULL;
	}
	slow = head;
	if (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
void print(node*head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}
int main() {
	node*head = NULL;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		construct(head, data);
	}
	print(head);
	cout << endl;
	head->next->next->next->next = head->next;
	node*res = detect(head);

	if (res != NULL) {
		cout << res->data;
	}
	else {
		cout << "Not found" << endl;
	}
}