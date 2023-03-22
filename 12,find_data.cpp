 #include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

int main ()
{
    node *head, *temp, *prev;
    int i,x, target;
    //Creating the first node
    head = new node;

    for (int a=0; a<1; a++)
    {
        cout<<"Enter data " << a + 1 << ": ";
        cin>>x;
    }


    head->data = x;
    head->next = NULL;
    temp = head;

    for(i=0; i<4; i++)
    {
        temp -> next =new node;
        temp = temp -> next;
        cout<<"Enter data " << i +2 << ": ";
        cin>>x;
        temp->data = x;
        temp->next = NULL;
    }

    //Printing out the linked list
    temp = head;

    cout << "The Current List:" <<endl;

    while (temp !=NULL)
    {
        cout<<temp->data << "\t";
        temp = temp->next;
    }


    cout << endl;
    cout << endl;
    cout << "Deleting the first node" << endl;
    cout << "The list after deletion:" << endl;

    //Deleting a node
    temp = head;
    head = head->next;
    delete temp;

    //Printing out the linked list

    temp = head;

    while (temp != NULL)
    {
        cout<<temp->data<< "\t";
        temp = temp->next;
    };

    cout << endl;
    cout << endl;
    cout << "Enter a data to search: ";
    cin >> target;

    int found = 0;

    for(int i=0; i<4; i++)
    {
        if(array[i] == target)
        found = 1;
    }
}
