#include<iostream>
using namespace std;

struct node{
	int mark;
	String name;
	String matrixnum;
	String email;
	*node next;
};

Class StudentList{
//property
	*node head;

//method/behavior

	void printName();
	void printAll();
	void createNode();
	int isEmpty();
}
