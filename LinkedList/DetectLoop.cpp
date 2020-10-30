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
void constructNode(node*&head, int data) {
	node*n = new node(data);
	n->next = head;
	head = n;
}
void reverse(node*&head) {
	node *curr = head;
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
void recursive(node*prev, node*curr, node*&head) {
	if (!curr) {
		return;
	}
	if (!curr->next) {
		head = curr;
		curr->next = prev;
		return;
	}
	recursive(curr, curr->next, head);
	curr->next = prev;
}
void print(node*head) {
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}
node* reverseK(node*&head, int k) {
	node*curr = head;
	node*prev = NULL;
	node*save;
	int count = 0;
	while (curr != NULL and count < k) {
		save = curr->next;
		curr->next = prev;
		prev = curr;
		curr = save;
		count++;
	}
	if (save != NULL) {
		head->next = reverseK(save, k);
	}
	return prev;
}
bool detectLoop(node*head) {
	unordered_set<node*>s;
	while (head != NULL) {
		if (s.find(head) != s.end())
			return true;
		s.insert(head);
		head = head ->next;
	}
	return false;
}
bool detectLoopFloydCycle(node*head) {
	node*slow = head, *fast = head;
	while (slow and fast and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}
int main() {
	node* head = NULL;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		constructNode(head, data);
	}
	// print(head);
	// reverse(head);
	// cout << endl;
	// print(head);
	// cout << endl;
	// recursive(NULL, head, head);
	print(head);
	// int k;
	// cin >> k;
	// head = reverseK(head, k);
	head->next->next->next->next = head;
	cout << detectLoopFloydCycle(head);

}