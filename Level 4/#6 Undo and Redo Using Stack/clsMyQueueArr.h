#pragma once
#include"clsDynamicArray.h"
#include<iostream>
using namespace std;

template<typename T >
class clsMyQueueArr 
{
protected :

	clsDynamicArray<T> MyQueue;

public:


	void push(T Value)
	{
		MyQueue.InsertAtEnd(Value);
	}

	void Print()
	{
		MyQueue.PrintList();
	}

	int Size()
	{
		return MyQueue.Size();
	}

	T front()
	{
		return MyQueue.GetItem(0);
	}

	T back()
	{
		return MyQueue.GetItem(MyQueue.Size() - 1);
	}

	void pop()
	{
		MyQueue.DeleteFirstItem();
	}

	T GetItem(int Index)
	{
		return MyQueue.GetItem(Index);
	}

	void Reverse()
	{
		MyQueue.Reverse();
	}

	void UpdateItem(int Index, T Value)
	{
		if (Index < 0 || Index >= MyQueue.Size())
		{
			return;
		}
		else
		MyQueue.OriginalArray[Index] = Value;
	}

	void InsertAfter(int Index, T Value)
	{
		MyQueue.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		MyQueue.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		MyQueue.InsertAtEnd(Value);
	}

	void Clear()
	{
		MyQueue.Clear();
	}

};

