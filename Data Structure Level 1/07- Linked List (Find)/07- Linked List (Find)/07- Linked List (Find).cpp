#include <iostream>
using namespace std;

// Create a node
class Node
{
public:
    int value;
    Node* next;
};

void InsertAtBeginning(Node*& head, int value)
{

    // Allocate memory to a node
    Node* new_node = new Node();

    // insert the data
    new_node->value = value;
    new_node->next = head;

    // Move head to new node
    head = new_node;

}

Node *Find(Node* Head, int Value)
{
    while (Head != NULL)
    {
        if (Head->value == Value)
        {
            return Head;
        }
        Head = Head->next;
    }
    return NULL;
}

// Print the linked list
void PrintList(Node* head)

{
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 5);

    PrintList(head);


    Node* Node1 = Find(head, 6);

    if (Node1 != NULL)
    {
        cout << "\nNode is Found\n";

    }
    else
        cout << "\nNode is Not Found\n";


    system("pause>0");

}