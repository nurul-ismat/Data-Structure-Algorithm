////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ2013- Data Structures and Algorithms
// Semester 1, 2018/2019
// Lab Test  - Question 2 Stack (25 marks)
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>
#include<cctype>

using namespace std;

class nodeStack
{
	public:
		char data;
		nodeStack *next;
};

class stack
{
	nodeStack *top;
	
	public:
		//To initialize top
		void createStack() {
			top = NULL;
		}
		
		//To check either a stack is empty or not 
		bool isEmpty() {
			return top == NULL;
		}
		
		//To get the item at the top of stack
		char stackTop() {
			return top->data;
		}
		
		void push(char);
		void pop();
};

//To insert a new item into a stack
void stack::push(char newItem)
{
	nodeStack *node = new nodeStack;
	
	if (node == NULL)
		cout << "Cannot allocate memory" << endl;
	else
	{
		node->data = newItem;
		node->next = top;
		top = node;
	}
}

//To delete the item from a stack
void stack::pop()
{
	nodeStack *delNode;
	
	delNode = top;
	top = delNode->next;
	delete delNode;
}

//Check if a character is an operator
bool isOperator(char ch)
{
	if ((ch == '+') || (ch == '*') ||
		   (ch == '-') || (ch == '/'))
		return true;
	else
		return false;
}

//Determine the precedence of the operator
int precedence(char ch) 
{ 
    switch (ch) 
    { 
    	case '+': 
    	case '-': return 1; 
  
    	case '*': 
    	case '/': return 2; 
    } 
    return -1; 
} 

int main()
{
	char ch;
	stack s;       							    //Stack
	string infix = "8 * (3 + 4) / 2 - 3 * 5";   //Infix expression
	string postfix = ""; 						//Postfix expression
	
	cout << "Convert infix to postfix" << endl;
	cout << "Infix: ";
	s.createStack();
	s.push('#');
 
    //Convert infix expression to postfix
	for (int i = 0; i < infix.length(); i++)
	{
		ch = infix[i];
		
		if (!isspace(ch))
			cout << ch;
		
		//If an operand is encountered, add it to postfix expression.	
		if (isdigit(ch))
			postfix += ch;

	    //-------------------------------------------------
		//Task 1: If a left parentheses is encountered, push 
		//it into a stack. (2 marks)




		
	    //-------------------------------------------------
		//Task 2: If an operator is encountered, then	
		//(1) Repeatedly pop from stack and add to postfix expression  
		//    each operator on the top of stack which has the same  
		//    precedence as or higher precedence than encountered operator.
		//(2) Add operator to stack. (8 marks)
			





		
	    //-------------------------------------------------
		//Task 3: If a right parentheses is encountered, then:
		//(1) Repeatedly pop from stack and add to postfix expression 
		//    each operator on the top of stack until a left  
		//    parentheses is encountered.
		//(2) Remove the left parentheses. (5 marks)
		









	}
	
	while (s.stackTop() != '#')
	{
		postfix += s.stackTop();
		s.pop();
	}
	
	cout << "\nPostfix: " << postfix << endl;


	int operand1, operand2, result;
	s.createStack();	

	//Evaluate postfix expression
	for (int i = 0; i < postfix.length(); i++)
	{
		ch = postfix[i];

		//If operand is encountered, push it onto stack 	
		if (isdigit(ch))
			s.push(ch - '0');
		else
		{
         //-------------------------------------------------
		 //Task 4: If an operator is encountered, then 
		 //(1) Pop the first two operands in stack
		 //(2) Evaluate the encountered operator using both operands 
		 //(3) Push the result of the evaluation to stack. (10 marks)
		      







		}
	}

	cout << "\nEvaluating postfix expression" << endl;
	cout << "Postfix expression: " << postfix << endl;
	cout << "Result = " << (int)s.stackTop() << endl;

 	return 0;    
}
