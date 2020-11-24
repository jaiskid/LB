#include<bits/stdc++.h>
using namespace std;
class twoStack {
private:
	int *arr;
	int size;
	int top1, top2;
public:
	twoStack(int n) {
		arr = new int;
		size = n;
		top1 = -1;
		top2 = size;
	}
	~twoStack() {
		delete[] arr;
	}
	void push1(int x) {
		if (top1 < top2 - 1) {
			top1++;
			arr[top1] = x;
		}
		else {
			cout << "Stack is overflow";
			exit(1);
		}
	}
	void push2(int x) {
		if (top1 < top2 - 1) {
			top2--;
			arr[top2] = x;
		}
		else {
			cout << "Stack is overflow";
			exit(1);
		}
	}
	int pop1() {
		if (top1 >= 0) {
			int x = arr[top1];
			top1--;
			return x;
		}
		else {
			cout << "Stack is underflow";
			exit(1);
		}
	}
	int pop2() {
		if (top2 < size) {
			int x = arr[top2];
			top2++;
			return x;
		}
		else {
			cout << "Stack is underflow";
			exit(1);
		}
	}
};
int main() {
	twoStack stack2(5);
	stack2.push1(5);
	stack2.push2(10);
	stack2.push2(15);
	stack2.push1(11);
	stack2.push2(7);
	cout << stack2.pop1() << endl;
	stack2.push2(40);
	cout << stack2.pop2() << endl;
}