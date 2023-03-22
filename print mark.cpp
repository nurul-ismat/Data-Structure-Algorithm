			//**********************NAME: NURUL ISMAT TANNI******************//
			//**********************MATRIC NO: A18CS4052********************//
			//**********************SECTION-10*****************************//
			//**********************HOME-WORK(1)**************************//

#include <iostream>
using namespace std;

struct node{
	double mrk;
	node *next;
};

int main(int argc, char** argv) {
	node *newnode;
	node *n1 = NULL;
	node *n2 = NULL;
	node *n3 = NULL;
	node *n4 = NULL;
	node *head;
	newnode=new node; newnode->mrk=3;
	n1=newnode;
	newnode=new node; newnode->mrk=5;
	
	n2=newnode;
	newnode=new node; newnode->mrk=7;
	
	n3=newnode;
	n4=new node;n4->mrk=9;
	newnode=NULL;
	
	head=n1;
	head->next=n2;
	n2->next=n3;
	n3->next=n4;
	
	n1=NULL;
	n2=NULL;
	n3=NULL;
	n4=NULL;
	
	//node*travel=NULL;
	node*travel=head;
	cout<<"mark is:"<<travel->mrk;
	
	travel=travel->next;
	cout<<"\nmark is:"<<travel->mrk;
	
	travel=travel->next;
	cout<<"\nmark is:"<<travel->mrk;
	
	travel=travel->next;
	cout<<"\nmark is:"<<travel->mrk;

	//***************************HOME-WORK****************************//	
	//create new node
	//step 1: newnode=new node;
	//step 2: newnode->next=head;
	//step 3: head=newnode;
	//step 4: print mark 11
	
	newnode=new node;
	newnode->mrk=11;
	newnode->next=NULL;
	travel->next=newnode;
	
	cout<<"\nmark is:11";
	cout<<"\n newnode : "<<newnode;
    cout<<"\n n1 : "<<n1;
    cout<<"\n n2 : "<<n2;
    cout<<"\n n3 : "<<n3;
    cout<<"\n n4 : "<<n4;
    
    cout<<"\n head : "<<head;
    //cout<<"\n head->next : "<<n2;
    cout<<"\n head->next :"<<head->next;
    cout<<"\n head : "<<newnode;
    
	
	return 0;
}
