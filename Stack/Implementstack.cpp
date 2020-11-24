#include<bits/stdc++.h>
using namespace std;
class MyStack {
private:
	int maxSize;
	int *StackArray;
	int top;
public:
	MyStack(int s) {
		maxSize = s;
		StackArray = new int;
		top = -1;
	}
	~MyStack() {
		delete[] StackArray;
	}
	void push(int j) {
		if (isFull)
			cout << "Stack is full";
		StackArray[++top] = j;
	}
	int pop() {
		return StackArray[top--];
	}
	int peek() {
		return StackArray[top];
	}
	bool isEmpty() {
		return (top == -1);
	}
	bool isFull() {
		return (top == maxSize - 1);
	}
};
int main() {
	int n;
	cin >> n;
	MyStack theStack(n);
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		theStack.push(data);
	}
	while (!theStack.isEmpty()) {
		cout << theStack.pop() << " ";
	}

}
