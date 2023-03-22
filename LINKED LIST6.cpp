#include <iostream>
#include <string>

using namespace std;

template <class T>
class LinkedList
{
private:
	struct node
	{
		T data;
		node * next;
	} *head;

public:
	LinkedList();
	~LinkedList();
	void add(T d);
	void remove(T d);
	void clear();
	void makeCircular();
	bool isCircular();
	void display(const char* s);
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
}	

template <class T>
LinkedList<T>::~LinkedList()
{
	node *p, *q;
	p = head;
	if(p == NULL) return;
	while(p) {
		q = p->next;
		delete p;
		p = q;
	}
}

template <class T>
void LinkedList<T>::add(T d)
{	
	node *p, *q;
	if(head == NULL) {
		head = new node;
		head->data = d;
		head->next = NULL;
		return;
	} 
	p = head;
	while(p->next != NULL) 
		p = p->next;
	q = new node;
	q->data = d;
	q->next = NULL;
	p->next = q;	
}

template <class T>
void LinkedList<T>::remove(T d)
{
	node *p, *q;
	if(head == NULL) return;
	p = head;
	while(p) {
		if(p->data == d) {
			q->next = p->next;
			delete p;
			return;
		}
		q = p;
		p = p->next;
	}
}

template <class T>
void LinkedList<T>::clear()
{
	node *p, *q;
	if(head == NULL) return;
	p = head;
	while(p) {
		q = p->next;
		delete p;
		if(q != head)  {
			head = NULL;
			return;
		}
		p = q;
	}
}

template <class T>
void LinkedList<T>::makeCircular()
{
	node *p;
	if(head == NULL || head->next == NULL) return;
	p = head;
	while(p) {
		if(p->next == NULL) {
			p->next = head;
			return;
		}
		p = p->next;
	}
}

template <class T>
bool LinkedList<T>::isCircular()
{
	node *p, *pp;
	if(head == NULL || head->next == NULL) return false;
	p = head;
	pp = head;
	while(pp) {
		p = p->next;
		if(pp->next == NULL) return false;
		pp = (pp->next)->next;
		if(p == pp) return true;
	}
	return false;
}

template <class T>
void LinkedList<T>::display(const char* s)
{
	node *p;
	if(head == NULL) return;
	p = head;
	while(p) {
		if(s == "string") 
			cout << p->data << endl;
		else
			cout << p->data << ' ';
		p = p->next;
		if(p != NULL) {
			if(p == head) return;
		}
	}
	if(s == "integer") cout << endl;
}
 
int main()
{
	LinkedList<string> sList;
	sList.add("Wolfgang Amadeus Mozart");
	sList.add("Franz Peter Schubert");
	sList.add("Pyotr Ilyich Tchaikovsky");
	sList.add("Clude-Achille Debussy");
	sList.add("Camille Saint-Saens");
	sList.display("string");
	sList.clear();

	LinkedList<int> iList;
	iList.add(40);
	iList.add(50);
	iList.add(60);
	iList.add(70);
	iList.add(80);
	iList.add(90);
	iList.add(100);
	iList.add(10);
	iList.add(20);
	iList.add(30);
	iList.display("integer");

	/* link last element to the first */
	iList.makeCircular();

	if(iList.isCircular()) cout <<"This is circular list\n";
	iList.display("integer");

	iList.clear();
	cout << "\ndisplay after clear()\n";
	iList.display("integer");

	return 0;
}
