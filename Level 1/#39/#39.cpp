#include <iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime CheckPrime(int Num)
{
	int M =round(Num / 2) ;
	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Num % Counter == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}
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

void CopyPrimeNumbers(int ArraSource[100], int ArraDestination[100], int ArrayLength, int& ArrayDestinationLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		if (CheckPrime(ArraSource[i])==enPrimeNotPrime::Prime)
		{
			AddArrayElement(ArraSource[i], ArraDestination, ArrayDestinationLength);
		}
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

	cout << "\nArray For Only Prime Numbers : " << endl;
	int Array2[100], Array2Length = 0;
	CopyPrimeNumbers(Array, Array2, ArrayLength, Array2Length);
	PrintArray(Array2, Array2Length);
	return 0;
}