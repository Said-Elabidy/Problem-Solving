#pragma once
#include <iostream>
using namespace std;

template <typename T >

class clsMyQueue
{

protected :
	int _Size = 0;

public :

	class Node
	{

	public :

		T Value;
		Node* next;
 
	};

	Node* head = NULL;

	void Push(T Value)
	{
		if (head == NULL)
		{
			Node* NewNode = new Node();

			NewNode->Value = Value;
			NewNode->next = NULL;
			head = NewNode;
			_Size++;
			return;
		}
		else
		{
			Node* Current = head;

			while (Current->next != NULL)
			{
				Current = Current->next;
			}

			Node* NewNode = new Node();
			NewNode->Value = Value;
			NewNode->next = NULL;

			Current->next = NewNode;
		}
		_Size++;

	}

	void Print()
	{
		Node* Current = head;

		if (Current == NULL)
		{
			return;
		}

		while (Current != NULL)
		{
			cout << Current->Value << " ";
			Current = Current->next;
		}
		cout << endl;

	}

	int Size()
	{
		return _Size;
	}

	T Front()
	{
		if (head == NULL)
		{
			return NULL;
		}

		return head->Value;
	}

	T Back()
	{
		if (head == NULL)
		{
			return NULL;
		}

		Node* Current = head;

		while (Current->next != NULL)
		{
			Current = Current->next;
		}

		return Current->Value;
	}

	void Pop()
	{
		if (head == NULL)
		{
			return ;
		}

		Node* Temp = new Node();
		Temp = head;
		head = head->next;
		
		delete Temp;

		_Size--;

	}
};


