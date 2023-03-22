/*NURUL ISMAT TANNI- A18CS4052*/

#include <iostream>

#include<stdio.h>

#include<stdlib.h>

using namespace std;

struct Node { //declaration link list

  int data;
  struct Node * next;
};
struct BSTNode //declaration binary search tree
{
  int data;
  BSTNode * left;
  BSTNode * right;
};

struct nodeGrade { // declaration grade
  char data;
  nodeGrade * next;
};

// Function to add a new node to the Linked List 
nodeGrade * add(char data) {
  nodeGrade * newnode = new nodeGrade;
  newnode -> data = data;
  newnode -> next = NULL;
  return newnode;
}

//push for linked list
void push(struct Node ** head, int data) {
  struct Node * newNode =
    (struct Node * ) malloc(sizeof(struct Node));

  newNode -> data = data;

  newNode -> next = ( * head);

  ( * head) = newNode;
}

// Function to convert the string to Linked List. 
// For grade
nodeGrade * string_to_SLL(string text, nodeGrade * head) {
  head = add(text[0]);
  nodeGrade * curr = head;

  // curr pointer points to the current node   
  // where the insertion should take place 
  for (int i = 1; i < text.size(); i++) {
    curr -> next = add(text[i]);
    curr = curr -> next;
  }
  return head;
}

void print(nodeGrade * head) //print the arrow after insert the grade
{
  nodeGrade * curr = head;
  while (curr != NULL) {
    cout << curr -> data << " -> ";
    curr = curr -> next;
  }
}

//Function to add a new node to the Binary Search Tree
BSTNode * getnewnode(int data) {
  BSTNode * temp = new BSTNode();
  temp -> data = data;
  temp -> left = temp -> right = NULL;
  return temp;
}

//insert node for bst
BSTNode * insertnode(struct BSTNode * root, int data) {
  if (root == NULL) {
    root = getnewnode(data);
  } else if (data <= root -> data) {
    root -> left = insertnode(root -> left, data);
  } else {
    root -> right = insertnode(root -> right, data);
  }
  return root;
}

int findmin(BSTNode * root) // method find the minimum element for bst
{
  if (root == NULL) {
    cout << "\nerror: tree is empty ";
    return -1;
  }
  BSTNode * current = root;
  while (current -> left)
    current = current -> left;
  return current -> data;
}
int findmax(BSTNode * root) // method find the maximum element for bst
{
  if (root == NULL) {
    cout << "\n error: tree is empty ";
    return -1;
  }
  BSTNode * current = root;
  while (current -> right)
    current = current -> right;
  return current -> data;
}

int largestElement(struct Node * head) // method find the maximum element for linklist
{
  int max = INT_MIN;

  while (head != NULL) {

    if (max < head -> data)
      max = head -> data;
    head = head -> next;
  }
  return max;
}

int smallestElement(struct Node * head) // method find the smallest element for linklist
{
  int min = INT_MAX;

  while (head != NULL) {

    if (min > head -> data)
      min = head -> data;

    head = head -> next;
  }
  return min;
}

void printList(struct Node * head) {
  while (head != NULL) {
    printf("%d -> ", head -> data);
    head = head -> next;
  }
  cout << "NULL" << endl;
}

float avgOfNodes(struct Node * head) //function average
{
  // if head = NULL 
  if (!head)
    return -1;

  int count = 0;
  int sum = 0;
  float avg = 0.0;

  struct Node * current = head;
  while (current != NULL) {
    count++;
    sum += current -> data;
    current = current -> next;
  }

  // calculate average 
  avg = (double) sum / count;

  return avg;
}

//main function
int main(int argc, char ** argv) {
  // Start with empty list 
  struct Node * head = NULL;
  struct BSTNode * root = NULL;

  string text = "abcdefabcdefabcdef"; //student grade

  nodeGrade * head1 = NULL;
  head1 = string_to_SLL(text, head1);

  //push all the values heree
  push( & head, 65.14);
  push( & head, 80.90);
  push( & head, 73.95);
  push( & head, 89.75);
  push( & head, 88.83);

  push( & head, 64.35);
  push( & head, 62.29);
  push( & head, 67.32);
  push( & head, 78.46);
  push( & head, 78.71);

  push( & head, 74.07);
  push( & head, 74.21);
  push( & head, 61.11);
  push( & head, 88.00);
  push( & head, 77.00);

  push( & head, 71.13);
  push( & head, 70.75);
  push( & head, 69.12);
  push( & head, 81.32);
  push( & head, 63.43);

  push( & head, 77.10);
  push( & head, 72.31);
  push( & head, 73.22);
  push( & head, 77.11);
  push( & head, 70.43);

  push( & head, 82.27);
  push( & head, 68.91);
  push( & head, 76.58);
  push( & head, 74.21);

  //push all values to BST
  root = insertnode(root, 65.14);
  root = insertnode(root, 80.90);
  root = insertnode(root, 73.95);
  root = insertnode(root, 89.75);
  root = insertnode(root, 88.83);

  root = insertnode(root, 64.35);
  root = insertnode(root, 62.29);
  root = insertnode(root, 67.32);
  root = insertnode(root, 78.46);
  root = insertnode(root, 78.71);

  root = insertnode(root, 74.07);
  root = insertnode(root, 74.21);
  root = insertnode(root, 61.11);
  root = insertnode(root, 88.00);
  root = insertnode(root, 77.00);

  root = insertnode(root, 71.13);
  root = insertnode(root, 70.75);
  root = insertnode(root, 69.12);
  root = insertnode(root, 81.32);
  root = insertnode(root, 63.43);

  root = insertnode(root, 77.10);
  root = insertnode(root, 72.31);
  root = insertnode(root, 73.22);
  root = insertnode(root, 77.11);
  root = insertnode(root, 70.43);

  root = insertnode(root, 82.27);
  root = insertnode(root, 68.91);
  root = insertnode(root, 76.58);
  root = insertnode(root, 74.21);

  //Initial function
  int x;
  int linkedListMenu;
  int bstMenu;

  //This is main menu
  cout << "------Main menu-------\n";
  cout << "[1] Linked List\n";
  cout << "[2] Binary Search Tree\n\n";
  cout << "Please choose one main menu:\t";
  cin >> x;

  if (x == 1) {

    cout << "\n------Menu-------\n";
    cout << "[1] Student Grade\n";
    cout << "[2] Highest Mark\n";
    cout << "[3] Lowest Mark\n";
    cout << "[4] Average\n\n";
    cout << "Please choose one menu:\t";
    cin >> linkedListMenu; //call for linked list function

    if (linkedListMenu == 1) {
      print(head1);
    } else if (linkedListMenu == 2) {
      cout << "Highest Mark of Student is : \t";
      cout << largestElement(head) << endl;
    } else if (linkedListMenu == 3) {

      cout << "Lowest Mark of Student is : \t";
      cout << smallestElement(head) << endl;

    } else if (linkedListMenu == 4) {
      cout << "Average of the marks is : \t";
      cout << avgOfNodes(head) << endl;
    }

  } else { //this is for bst
    cout << "\n------Menu-------\n";
    cout << "[1] Student Grade\n";
    cout << "[2] Highest Mark\n";
    cout << "[3] Lowest Mark\n";
    cout << "[4] Average\n\n";
    cout << "Please choose one menu:\t";
    cin >> bstMenu; //call for bst function

    if (bstMenu == 1) {
      print(head1);
    } else if (bstMenu == 2) {
      cout << "Highest Mark of Student is : \t";
      cout << findmax(root) << endl;
    } else if (bstMenu == 3) {

      cout << "Lowest Mark of Student is : \t";
      cout << findmin(root) << endl;

    } else if (bstMenu == 4) {
      cout << "Average of the marks is : \t";
      cout << avgOfNodes(head) << endl;
    }
  }
  return 0;
}
