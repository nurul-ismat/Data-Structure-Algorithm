#include <cstddef>
#include <iostream>

using namespace std;

class Node {
    public:
        int data;
    Node * next;
};

void print_list(Node * n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main() {
    Node * head = NULL;
    Node * second = NULL;
    Node * third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    print_list(head);
}
    int Menu(){
            int menu = 0;
            while(menu < 1 || menu > end){
                cout << "========MENU LIST=========" << endl;
                cout << "What you wanted to do with the List" << endl;
                cout << "1. Grade calculation " << endl;
                cout << "2. Display all student " << endl;
                cout << "3. Add Student " << endl;
                cout << "4. Search student by number " << endl;
                cout << "5. Delete student by number " << endl;
                cout << "6. End " << endl;
                cout << "==========================" << endl;
                cin >>;
                if(menu < 1 || menu > end){
                    cout << "\n\nPLEASE CHOOSE BETWEEN 1 - 5" << endl << endl;
                }
            }
            switch (menu)
            {
            case 1:
                displayTotal();
                break;
            case 2:
                displayList(root);
                break;
            case 3:
                displayAddNode();
                break;
            case 4:
                displaySearch(menu);
                break;
            case 5:
                displaySearch(menu);
                break;
            case 6:
                cout << "=========THANK YOU========" << endl;
            default:
                break;
            }
            return menu;
        }

