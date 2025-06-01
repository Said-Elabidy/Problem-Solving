#include <iostream>
#include<cstdlib>
using namespace std;

int ReadPositiveNumber()
{
	int Num = 0;
	do
	{
		cout << "Please enter a Number ?" << endl;
		cin >> Num;
	} while (Num <= 0);
	return Num;
}

int RandomNum(int From, int To)
{
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

void FillArrayWithRandomNumbers(int Array[100], int& ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		Array[i] = RandomNum(1, 100);
	}
}

void AddArrayElement(int Num, int Array[100], int& ArrayLength)
{
	ArrayLength++;
    Array[ArrayLength - 1] = Num;
}

void CopyArrayUsingAddArrayElement(int ArraSource[100], int ArraDestination[100], int ArrayLength, int &ArrayDestinationLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		AddArrayElement( ArraSource[i], ArraDestination, ArrayDestinationLength);
	}
}

void PrintArray(int Array[100], int& ArrayLength)
{
	cout << "Array Elements : " << endl;
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

	ArrayLength = ReadPositiveNumber();
	FillArrayWithRandomNumbers(Array, ArrayLength);
	PrintArray(Array, ArrayLength);

	cout << "Array After Copy : " << endl;
	int Array2[100], Array2Length = 0;
	CopyArrayUsingAddArrayElement(Array, Array2, ArrayLength,Array2Length);
	PrintArray(Array2, Array2Length);
	return 0;

}

