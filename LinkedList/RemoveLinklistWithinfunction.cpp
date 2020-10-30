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
}
void removeLoop(Node* head)
{
	// code here
	// code here
// just remove the loop without losing any nodes
	Node* slow = head, *fast = head;

	while (fast and fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}

	if (slow == fast) {

		slow = head;
		if (slow == fast) {
			while (fast->next != slow) fast = fast->next;
		}
		else
		{
			while (slow->next != fast->next) {
				slow = slow->next;
				fast = fast->next;

			}
		}
		fast->next = NULL;

	}
}
bool detect(node*head) {
	node*slow = head;
	node*fast = head;
	while (slow and fast and fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;
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
	// print(head);
	head->next->next->next->next->next = head->next->next;
	// cout << detect(head);
	removeLoop(head);
	// cout << detect(head);
	print(head);
}