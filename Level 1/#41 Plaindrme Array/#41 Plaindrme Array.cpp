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
void FillArrayWithNumbers(int Array[100], int& ArrayLength)
{
	cout << "Please enter Array Elements ?\n";
	for (int i = 0; i < ArrayLength; i++)
	{
		cin >> Array[i];
	}
}

bool IsPalindrom(int Array[100], int & ArrayLength)
{
	
	for (int i = 0; i < ArrayLength; i++)
	{
		if (Array[i] != Array[ArrayLength-i-1])
		{
			return false;
		}
	}
	return  true;
	
}

void PrintAndCheckPalindrom(int Array[100], int & ArrayLength)
{
	if (IsPalindrom(Array, ArrayLength))
	{
		cout << "It's Palindrom Array.\n";
	}
	else
		cout << "It's Not Palindrom Array.\n";
}

void PrintArray(int Array[100], int& ArrayLength)
{
	cout << "Array Elements : " << endl;
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Array[i];
		cout << " ";
	}
	cout << endl << endl;
}



int main()
{
	int Array[100], ArrayLegnth = 0;
	ArrayLegnth = ReadPositiveNumber("Please enter Array Legnth ");

	FillArrayWithNumbers(Array, ArrayLegnth);
	PrintArray(Array, ArrayLegnth);

	PrintAndCheckPalindrom(Array, ArrayLegnth);
	return 0;


}

