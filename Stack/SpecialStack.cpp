#include<bits/stdc++.h>
using namespace std;
stack<int> s;
void push(int x) {
	s.push(x);
}
bool isFull(int n) {
	if (s.size() == n) {
		return true;
	}
	return false;
}
int pop() {
	int a = s.top();
	s.pop();
	return a;
}
bool isEmpty() {
	if (s.size() == 0) {
		return true;
	}
	return false;
}
int getMin() {
	int min = INT_MAX;
	while (!s.empty()) {
		if (min > s.top()) {
			min = s.top();
		}
		s.pop();
	}
	return min;
}
int getMax() {
	int max = INT_MIN;
	while (!s.empty()) {
		if (max < s.top()) {
			max = s.top();
		}
		s.pop();
	}
	return max;
}
int main() {

	int n, a;
	cin >> n;
	while (!isEmpty()) {
		cout << pop();
	}
	while (!isFull(n)) {
		cin >> a;
		push(a);
	}
	cout << getMax() << endl;
	return 0;
}