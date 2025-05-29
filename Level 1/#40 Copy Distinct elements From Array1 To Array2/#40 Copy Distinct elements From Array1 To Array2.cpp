#include <iostream>
using namespace std;

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)

			return i;
	}
	return -1;
}
 bool IsNumberInArray(int Number, int arr[100], int arrLength) 
 { 
	 return FindNumberPositionInArray(Number, arr, arrLength) != -1;
 } 

void AddArrayElement(int Num, int Array[100], int& ArrayLength)
{
	ArrayLength++;
	Array[ArrayLength - 1] = Num;
}
void FillArrayWithNumbers(int Array[100], int& ArrayLength)
{
	ArrayLength = 10;
	Array[0] = 10;
	Array[1] = 10;
	Array[2] = 10;
	Array[3] = 50;
	Array[4] = 50;
	Array[5] = 70;
	Array[6] = 70;
	Array[7] = 70;
	Array[8] = 70;
	Array[9] = 90;
}

void CopyDistinctNumbers(int ArraSource[100], int ArraDestination[100], int ArrayLength, int& ArrayDestinationLength)
{
	
	for (int i = 0; i < ArrayLength; i++)
	{
		if (!IsNumberInArray(ArraSource[i],ArraDestination,ArrayLength))
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
	int Array[100], ArrayLength1 = 0;

	FillArrayWithNumbers(Array, ArrayLength1);
	PrintArray(Array, ArrayLength1);

	int Array2[100], ArrayLength2 = 0;
	CopyDistinctNumbers(Array, Array2, ArrayLength1, ArrayLength2);

	cout << "Copy only Distinct Numbers" << endl;
	PrintArray(Array2, ArrayLength2);



}

