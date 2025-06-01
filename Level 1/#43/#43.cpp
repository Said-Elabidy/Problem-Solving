#include <iostream>
#include<cstdlib>
using namespace std;

int ReadPositiveNumber()
{
	int Num = 0;
	do
	{
		cout << "Please enter  Number of Elements in Array?\n";
		cin >> Num;
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

int CountOfEvenNumbersInArray(int Array[100], int& ArrayLength)
{
	int Counter = 0;
	for (int i = 0; i < ArrayLength; i++)
	{
		if (Array[i] % 2 == 0)
		{
			Counter++;
		}

	}
	return Counter;
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
	srand((unsigned)time(NULL));
	int Array[100], ArrayLength = 0;
	ArrayLength = ReadPositiveNumber();
	FillArrayWithRandomNumbers(Array, ArrayLength);

	cout << "\nArray Elements : \n";
	PrintArray(Array, ArrayLength);

	cout << "Even Numbers Count is : " << CountOfEvenNumbersInArray(Array, ArrayLength);
	return 0;

}
