#include <iostream>
using namespace std;

class Node
{
public:

	int Value;
	Node* next;
};

void InsertNodeAtTheBegining(Node*& head, int Value)
{
	Node* NewNode=new Node();

	NewNode->Value = Value;
	NewNode->next = head;
	head=NewNode;
	
}

Node *Find(Node* Head, int Value)
{
	if (Head == NULL)
	{
		return NULL;
	}

	while (Head != NULL)
	{
		if(Head->Value==Value)
		{
			return Head;

		}
		Head = Head->next;
	}

	return NULL;
}

void InsertAtTheEnd(Node*& Head, int Value)
{
	Node* NewNode = new Node();
	NewNode->Value = Value;
	NewNode->next = NULL;

	Node* LastNode = Head;

	while (LastNode->next != NULL)
	{
		LastNode = LastNode->next;
	}

	LastNode->next= NewNode;

}
 
void InsertAfter(Node*& Head, int BaseValue, int NewValue)
{
	Node* Current = Head, * Prev = Head;

	Node* NewNode = new Node();
	NewNode->Value = NewValue;
	NewNode->next = NULL;
	if (Head == NULL)
	{
		Head = NewNode;
	}

	while (Current != NULL&&Current->next!=NULL)
	{
		
		if (Current->Value == BaseValue)
		{
			Prev->next = NewNode;
			NewNode->next = Current;
			return;
		}
		Prev = Current;
		Current = Current->next;
	}
}

void DeleteNode(Node*& Head, Node* NodeToDelete)
{
	Node* Current = Head,*Prev = Head;

	if (Head->next == NULL)
	{
		Head = NULL;
		return;
	}

	while (Current != NULL&&Current->next!=NULL)
	{
		if (Current == NodeToDelete)
		{
			Prev->next = Current->next;
			
		}
		Prev = Current;
		Current = Current->next;
	}
}

void DeleteFirstNode(Node*& Head)
{
	Node* NewNode = Head;
	Head = NewNode->next;
    delete NewNode;
}


void DeleteLastNode(Node*& Head)
{
	Node* Current = Head, * Prev = Head;

	if (Head->next == NULL)
	{
		Head = NULL;
		return;
	}

	while (Current != NULL && Current->next != NULL)
	{
		Prev = Current;
		Current = Current->next;
	}
	Prev->next = NULL;
	delete Current;
}
void Print(Node* head)
{
	while (head != NULL)
	{
		cout << head->Value << " ";
		head = head->next;
	}
}


int main()
{
	Node* Head = NULL;

	InsertNodeAtTheBegining(Head, 1);	
	InsertNodeAtTheBegining(Head, 2);
	InsertNodeAtTheBegining(Head, 3);
	InsertNodeAtTheBegining(Head, 4);
	InsertNodeAtTheBegining(Head, 5);
	Print(Head);
	cout << endl;
	DeleteLastNode(Head);
	Print(Head);

	system("pause>0");
}


