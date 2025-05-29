#include <iostream>
using namespace std;

int ReadPositiveNumber(string Ask)
{
	int Num = 0;
	do
	{
		cout << Ask << endl;
		cin >> Num;
	} while (Num <= 0);
	return Num;
}

void ReadArray(int  Arr[100], int& ArrayLength)
{
	cout << "Please enter Number of Elements ?\n";
	cin >> ArrayLength;
	cout << "\n Enter Array Elements : \n";
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << "Element [" << i + 1 << "] "<< ": ";
		cin >> Arr[i];
		cout << endl;
	}
}

void PrintArray(int Arra[100], int ArrayLength)
{
	cout << "Array Elements ";
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Arra[i] << " ";
	}
	cout << endl;
}

int CheckRepeatedDigit(int Num, int Arra[100], int ArrayLength)
{
	int Counter = 0;
	for (int i = 0; i < ArrayLength; i++)
	{
		if (Num == Arra[i])
		{
			Counter = Counter + 1;
		}

	}
	return Counter;
}

int main()
{
	int Arra[100], ArrayLength, NumbertoCheck;
	 

	ReadArray(Arra, ArrayLength);

	cout << "The Original Array : ";

	PrintArray(Arra, ArrayLength);
	cout << endl;
	NumbertoCheck = ReadPositiveNumber("Please enter Number to Check ?");

	cout << NumbertoCheck << " is Repeated " << CheckRepeatedDigit(NumbertoCheck, Arra, ArrayLength) << " Time(s)." << endl;
	return 0;




}

