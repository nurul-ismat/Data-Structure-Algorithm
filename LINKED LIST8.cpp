#include <iostream>

using namespace std;

class Stack
{
public:
	Stack();
	~Stack();
	void push(int);
	int pop();
	int peek();
	friend void print(Stack&);

private:
	typedef struct node {
		node *next;
		int data;
	} NODE;

	NODE *top;
};

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{
	while(top) {
		NODE *tmp = top;
		top = top->next;
		delete tmp;
	}
}

void Stack::push(int n) 
{
	NODE *ptr = new NODE;
	ptr->next = top;
	ptr->data = n;
	top = ptr;
}

int Stack::pop()
{
	NODE *tmp = top;
	int val = top->data;
	top = top->next;
	delete tmp;
	return val;
}

int Stack::peek()
{
	return top->data;
}

void print(Stack &s)
{
	Stack::NODE *cur = s.top;
	while(cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main()
{
	Stack *st = new Stack;
	st->push(10);
	st->push(20);
	st->push(30);
	st->push(40);
	st->push(50);
	print(*st);
	st->pop();
	st->pop();
	print(*st);
	cout << "current top=" << st->peek();
	return 0;
}
