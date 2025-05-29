#include <iostream>
using namespace std;

int ReadPositiveNumber()
{
	int Num = 0;
	do
	{
		cout << "Please enter a Number ?";
		cin >> Num;
	} while (Num <= 0);
	return Num;
}

void AddArrayElement(int Num, int Array[100], int &ArrayLength)
{
	ArrayLength++;
	Array[ArrayLength - 1] = Num;
}

void InputUserNumberInArray(int Array[100], int &ArrayLength)
{
	bool AddMore = true;
	do
	{
		AddArrayElement(ReadPositiveNumber(), Array, ArrayLength);
		cout << "Do You want to Add more Number ? [0]:No , [1]:Yes.";
		cin >> AddMore;
	} while (AddMore);
}

void PrintArray(int Array[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Array[i];
		cout << " ";
	}
	cout << endl;
}
int main()
{
	int Array[100], ArrayLength = 0;

	InputUserNumberInArray(Array, ArrayLength);

	cout << "Array Length : " << ArrayLength << endl;
	cout << "Array Elements : ";
	PrintArray(Array, ArrayLength);

	return 0;


}

