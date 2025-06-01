#include <iostream>
#include <cstdlib>
using namespace std;


int ReadPositiveNumber(string Ask)
{
	int Num = 0;
	do
	{
		cout << Ask << endl;
		cin >> Num;
		cout << endl;
	} while (Num <= 0);
	return Num;
}

int RandomNumber(int From, int To)
{
	int RandNum = 0;
	RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillArrayWithRandomNumbers(int Array[100], int& ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		Array[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int Array[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Array[i];
		cout << " ";
	}
	cout << endl << endl;
}

bool IsNumberInArray(int Array[100], int Num, int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		if (Array[i] == Num)
		{
			return true;
		}

	}
	return false;
}

void PrintFoundorNot(int Array[100], int Num, int ArrayLength)
{
	cout << "The Numbers Your Are Looking for is : " << Num << endl;
	if (IsNumberInArray(Array, Num, ArrayLength))
	{
		cout << "Yes, the Number is found :-)\n";
	}
	else
		cout << "The Number is Not Found :-(" << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100];

	int ArrayLength = 0;

	ArrayLength = ReadPositiveNumber("Please enter Number Of Elements ?");

	FillArrayWithRandomNumbers(Array, ArrayLength);

	cout << "Array Elements : \n\n";
	PrintArray(Array, ArrayLength);

	int Num = ReadPositiveNumber("Please enter a Number to search for ?");

	PrintFoundorNot(Array, Num, ArrayLength);
	return 0;


}
