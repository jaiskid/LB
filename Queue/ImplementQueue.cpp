#include<bits/stdc++.h>
using namespace std;
class Queue {
private:
	int top, end, n;
	int *queue;
public:
	Queue(int c) {
		top = end = 0;
		n = c;
		queue = new int;
	}
	~Queue() {
		delete[] queue;
	}
	void Enqueue(int data) {
		if (n == end) {
			cout << "Queue is Full";
			return;
		}
		else {
			queue[end++] = data;

		}
		return;
	}
	void Dequeue() {
		if (top == end) {
			cout << "Queue is Empty";
		}
		else {
			for (int i = 0; i < end - 1; i++) {
				queue[i] = queue[i + 1];
			}
			end--;
		}
		return;
	}
	void Display() {
		int i;
		if (top == end) {
			cout << "Queue is empty";
			return;
		}
		for (int i = top; i < end; i++) {
			cout << queue[i] << " ";
		}
		return;
	}
	void Front() {
		if (top == end) {
			cout << "Queue is empty";
		}
		cout << queue[top];
		return;
	}
};
int main() {
	Queue q(5);
	q.Display();
	cout << endl;
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);
	q.Display();
	cout << endl;
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Front();
	cout << endl;
	q.Display();
	return 0;
}