#include<iostream>
#include<cstdlib>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int RandomNum(int From, int To)
{
	int Num = rand() % (To - From + 1) + From;
	return Num;
}

void FillArrayWithRandomNumbers(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNum(0 , 100);
	}
}
void ReversedArray(int arrSource[100], int arrDestination[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrDestination[i] = arrSource[arrLength - 1 - i];
	}
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main()
{
	//Seeds the random number generator in C++, called only once    
	srand((unsigned)time(NULL));

	int arr[100];

	int arrLength = ReadPositiveNumber("\nEnter number of elements : \n");

	FillArrayWithRandomNumbers(arr, arrLength);

	PrintArray(arr, arrLength);

	int arr2[100];
	ReversedArray(arr,arr2, arrLength);

	cout << "\nArray elements after Reversed :\n";
	PrintArray(arr2, arrLength);

	return 0;
}