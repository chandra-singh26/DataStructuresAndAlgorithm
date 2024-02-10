#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
public:
    void pushNode(Node **head, int val);
    void printNode(Node *head);
    int findMiddleElement(Node *head);
};

void LinkedList::pushNode(Node **head, int val){
    Node *new_node = new Node();
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

void LinkedList::printNode(Node *head){
    Node *temp = head;
    while(temp)
    {
        cout << temp->data << "->" ;
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int LinkedList::findMiddleElement(Node *head){
    int middle_ele = -1;
    Node *slow_ptr = head, *fast_ptr = head;
    if(head != NULL)
    {
        while(fast_ptr && fast_ptr->next)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        middle_ele = slow_ptr->data;
    }
    return middle_ele;
}
//Driver code
int main(){
    Node *head = NULL;
    LinkedList *temp = new LinkedList();
    for(int i = 6; i > 0; i--)
    {
        temp->pushNode(&head, i);
    }
    temp->printNode(head);
    int middle_ele = temp->findMiddleElement(head);
    cout << "Middle element: " << middle_ele << endl;
    return 0;
}