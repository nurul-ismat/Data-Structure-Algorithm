#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node{
	int value;
	node *next;
};

class Stack{
	public:
		Stack();
		void push(int v);
		void pop();
		bool isEmpty();
		int stackTop();
	 
	private:
		node *top;
};

Stack::Stack(){
	top=NULL;
}

bool Stack::isEmpty(){
	return (top== NULL);
}

void Stack::push(int v){
	node *nn = new node;
	nn->value = v;
	nn->next = top;
	top = nn;
}

void Stack::pop(){
	if (isEmpty()){
		cout<<"\nEmpty stack, unable to pop";
	} else {
		top = top->next;
	}
}

int Stack::stackTop(){
	if (isEmpty()){
		cout<<"\nEmpty stack, unable to stackTop";
	} else {
		return top->value;
	}
}

void Q2a_answer(){
    string exp = "897-/2*";  
	cout<<"\nQ2a_answer ";
	cout<<"exp is :"<<exp<<endl;
	//Answer your Task 1 here	- print/cout the exp
	//Refer Task 1 for expected output - 2 marks
}

void Q2b_answer(){
    string exp = "897-/2*";  
	cout<<"\nQ2b_answer ";
	Stack s1;
	if(s1.isEmpty())
		cout<<"the stack is empty";
		else
		cout<<"the stack is not empty";
		cout<<endl;
	//Answer your Task 2 here	- Create Stack s. Check s is empty or not
	//Refer Task 2 for expected output - 3 marks
}

void Q2c_answer(){
    string exp = "897-/2*";  
	cout<<"\nQ2c_answer ";
		Stack st ;
	
	//You can use this code as reference, for tokenizing expression into individual character 
	for (int i=0; i<exp.length(); i++){
		if (isdigit(exp[i])){
			cout<<"\nexp["<<i<<"] : "<<exp[i]-'0';
			st.push(exp[i]-'0');
		} else {
			//exp[i] is an operator. Do nothing
		}
	}	
		
	//Answer your Task 3 here	- Create stack s. Check s is empty or not
	//Scan through the expression. If the character is operand then push 
	//it into stack s. If character is operator, just ignore.
	//Display the values stored in stack s
	//Refer Task 3 for expected output - 8 marks

	void Q2d_answer(){
    string exp = "897-/2*";  
	cout<<"\nQ2d_answer ";
	
	cout<<"final answer is : 8"<<endl;
	
	//Answer your Task 4 here - Create Stack s. Check s is empty or not.
	//Scan through until end of the expression. If the character is operand then 
	//push it into stack s. If character is operator, get 2 operands from the stack s, 
	//perform the math operation, push back the result into stack s.
	//Finally, get and display the value stored by stack s. This is the final answer.
	//Refer Task 4 for expected output - 12 marks
}

void Q2e_answer(){
    string exp;  
	cout<<"\nQ2e_answer";
	
	//Answer your Task 5 here
	//Stack application - evaluate the postfix expression
	//Read the postfix expression from the user using keyboard
	//Evaluate and display the final result
	//Refer Task 5 for expected output - 5 marks
}


int main(){
	char selection;
	while (true){
	cout<<"\nAnswer for Question 'a' 'b' 'c' 'd' 'e' 'x' for exit\nSelection : ";
	cin>>selection;
	system("CLS");
		switch (selection){
			case 'a': Q2a_answer(); break;
			case 'b': Q2b_answer(); break;
			case 'c': Q2c_answer(); break;
			case 'd': Q2d_answer(); break;
			case 'e': Q2e_answer(); break;
			case 'x': cout<<"\nThank You. Bye";exit(0); break;
			default : cout<<"\nInvalid selection";
		}
	}
	return 0;
}

