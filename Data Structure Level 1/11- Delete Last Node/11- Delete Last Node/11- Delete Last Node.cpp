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

//Delete Last Node 
void DeleteLastNode(Node*& head)
{
    Node* Current = head, *Prev = head;

    if (head == NULL)
    {
        return; 
    }

    if (head->next == NULL)
    {
        head = NULL;
        return;
    }

    while (Current != NULL && Current->next != NULL)
    {
        Prev= Current;

        Current = Current->next;
    }

    Prev->next = NULL;
    delete Current;


}

// Print the linked list
void PrintList(Node* head)

{
    cout << "\n";
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
    DeleteLastNode(head);
    cout << endl;
    PrintList(head);

    system("pause>0");

}