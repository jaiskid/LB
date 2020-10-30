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
void print(node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}
void reverse(node*&head) {
	node*curr = head;
	node* prev = NULL;
	node*save;
	while (curr) {
		save = curr->next;
		curr->next = prev;
		prev = curr;
		curr = save;
	}
	head = prev;
}
void recursiveReverse(node*prev, node*curr, node*&head) {
	if (!curr)
		return;
	if (!curr->next) {
		head = curr;
		curr->next = prev;
		return;
	}
	recursiveReverse(curr, curr->next, head);
	curr->next = prev;
}
node* reverseInKgroup(node*&head, int k) {
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
	if (save != NULL)
		head->next = reverseInKgroup(save, k);
	return prev;
}
bool detectCycle(node*head) {
	unordered_set<node*> s;
	while (head) {
		if (s.find(head) != s.end()) {
			return true;
		}
		s.insert(head);
		head = head ->next;
	}
	return false;
}
bool floydCycleDetection(node*head) {
	node*slow = head;
	node*fast = head;
	while (slow and fast and fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}
void removal(node*slow, node*&head) {
	node*ptr1;
	node*ptr2;
	/* Set a pointer to the beginning of the Linked List and
	 move it one by one to find the first node which is
	 part of the Linked List */
	ptr1 = head;
	while (1) {
		/* Now start a pointer from loop_node and check if it ever
		reaches ptr2 */
		ptr2 = slow;
		while (ptr2->next != slow and ptr2->next != ptr1) {
			ptr2 = ptr2->next;
		}
		/* If ptr2 reahced ptr1 then there is a loop. So break the
		loop */
		if (ptr2->next == ptr1)
			break;
		/* If ptr2 did't reach ptr1 then try the next node after ptr1 */
		ptr1 = ptr1->next;
	}
	ptr2 ->next = NULL;
}
bool remover(node*&head) {
	node*slow = head;
	node*fast = head;
	while (slow and fast and fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			removal(slow, head);
			return true;
		}
	}
	return false;
}
void counterlooper(node*slow, node*&head) {
	node*ptr1 = slow;
	node*ptr2 = slow;
	// Count the number of nodes in loop
	int k = 1, i;
	while (ptr1->next != ptr2) {
		ptr1 = ptr1->next;
		k++;
	}
	// Fix one pointer to head
	ptr1 = head;
	// And the other pointer to k nodes after head
	ptr2 = head;
	for (i = 0; i < k; i++) {
		ptr2 = ptr2->next;
	}
	/*  Move both pointers at the same pace,
	  they will meet at loop starting node */
	while (ptr2 != ptr1) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	while (ptr2->next != ptr1) {
		ptr2 = ptr2->next;
	}
	ptr2->next = NULL;
}
bool detecter(node*&head) {
	node*slow = head;
	node*fast = head;
	while (slow and fast and fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			counterlooper(slow, head);
			return true;
		}
	}
	return false;
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
	reverse(head);
	cout << endl;
	print(head);
	recursiveReverse(NULL, head, head);
	cout << endl;
	print(head);
	head = reverseInKgroup(head, 2);
	cout << endl;
	print(head);
	head->next->next->next = head;
	cout << endl;
	cout << detectCycle(head);
	cout << endl;
	cout << floydCycleDetection(head);
	remover(head);
	cout << endl;
	cout << detectCycle(head);
	cout << endl;
	cout << floydCycleDetection(head);

}