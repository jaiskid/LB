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
void removeLoop(node* slow, node*&head) {
	node* ptr1;
	node* ptr2;
	ptr1 = head;
	while (1) {
		ptr2 = slow;
		while (ptr2->next != slow and ptr2->next != ptr1)
			ptr2 = ptr2->next;
		if (ptr2->next == ptr1)
			break;
		ptr1 = ptr1->next;
	}
	ptr2->next = NULL;
}
bool detectNremove(node*head) {
	node*slow = head;
	node* fast = head;
	while (slow and fast and fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			removeLoop(slow, head);
			return true;
		}
	}
	return false;
}
void print(node* head) {
	while (head!=NULL) {
		cout << head->data << " ";
		head = head->next;
	}

}
int main() {
	node *head = NULL;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		construct(head, data);
	}
	print(head);
	 head->next->next->next->next->next = head->next->next;
	detectNremove(head);
	cout << endl;
	print(head);
}