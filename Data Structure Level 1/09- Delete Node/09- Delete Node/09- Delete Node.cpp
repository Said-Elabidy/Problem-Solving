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

Node* Find(Node* head, int Value)
{

    while (head != NULL) {

        if (head->value == Value)
            return head;


        head = head->next;
    }

    return NULL;

}

// Insert a node after a node
void InsertAfter(Node* Prev_node, int Value) {

    if (Prev_node == NULL) {
        cout << "the given Previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();
    new_node->value = Value;
    new_node->next = Prev_node->next;
    Prev_node->next = new_node;
}

// Insert at the end
void InsertAtEnd(Node*& head, int Value) {

    Node* new_node = new Node();

    new_node->value = Value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node* LastNode = head;
    while (LastNode->next != NULL)
    {
        LastNode = LastNode->next;
    }

    LastNode->next = new_node;
    return;
}

// Delete a node
void DeleteNode(Node*& head, int Value) {

    Node* Current = head; // تشير الى العقدة الحالية
    Node* Prev = head;    // تشير الى العقدة قبل الحالية (السابقة)ـ

    // ------------------------------------------------------------------------------
    if (head == NULL) // اذا كانت القائمة فارغة
    {
        return;
    }

    // ------------------------------------------------------------------------------
    // حالة خاصة: لحذف العقدة الاولى
    if (Current->value == Value)
    {
        head = Current->next;  // نأخذ ما تشير اليه عقدة الرأس قبل حذفها
        delete Current;
        return;
    }

    // ------------------------------------------------------------------------------
    while (Current != NULL)
    {
        if (Current->value == Value) // اذا عثر على العقدة المطلوب حذفها
        {
            Prev->next = Current->next; // أخذ مؤشر العقدة الحالية قبل حذفها ونضعه في العقدة السابقة
            delete Current;
            return;
        }
        Prev = Current; // بعد عدم العثور على العقدة..جعل العقدة السابقة تساوي الحالية
        Current = Current->next; // جعل العقدة الحالية تتقدم وتأخذ عقدة أخرى 
    }

    // ------------------------------------------------------------------------------
    if (Current == NULL) // الرجوع بعد ان تم فحص كافة العقد ولم يتم العثور على أي تطابق
        return;
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

    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);
    InsertAtEnd(head, 6);
    PrintList(head);



    DeleteNode(head, 4);
    PrintList(head);

    system("pause>0");

}