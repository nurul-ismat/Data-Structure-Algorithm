#include <iostream>

using namespace std;

class Node {
    public:
        int data;
    Node * next;
};

int main() {
    Node * head = NULL;
    Node * second = NULL;
    Node * third = NULL;
    
/*each node is pointing to NULL at first since 
the pointers will be added later as i input the data*/

    head = new Node();
    second = new Node();
    third = new Node();
}
