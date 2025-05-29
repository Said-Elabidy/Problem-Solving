#include<iostream>
using namespace std;

class Node
{
public : 
	int Value;
	Node* next;
};

int main()
{
	//initializing pointers in the memory
	Node* Node1 =new Node();
	Node* Node2 =new Node();
	Node* Node3 =new Node();
	Node* Head = Node1;

	// Assigning Values
	Node1->Value = 1;
	Node2->Value = 2;
	Node3->Value = 3;
	
    // Linking Pointer Address
	Node1->next = Node2;
	Node2->next = Node3;
	Node3->next = NULL;

	// Print and Assigning Head to next References
	while (Head != NULL)
	{
		cout << Head->Value << endl;

		Head = Head->next;
	}


	system("pause>0");
}