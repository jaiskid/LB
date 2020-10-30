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
	cout << endl;
}
void removeUnsorted(node*&head) {
	node*ptr1, *ptr2, *dup;
	ptr1 = head;
	while (ptr1 != NULL and ptr1->next != NULL) {
		ptr2 = ptr1;
		while (ptr2->next != NULL) {
			if (ptr1->data == ptr2->next->data) {
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(dup);
			}
			else {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}
void removeDuplicate(node*head) {
	node*curr = head;
	node*prev = NULL;
	unordered_set<int>seen;
	while (curr != NULL) {
		if (seen.find(curr->data) != seen.end()) {
			prev->next = curr->next;
			delete(curr);
		}
		else {
			seen.insert(curr->data);
			prev = curr;
		}
		curr = prev->next;
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
	removeUnsorted(head);
	print(head);
}