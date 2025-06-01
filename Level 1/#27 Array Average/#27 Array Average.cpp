#include <iostream>
#include <cstdlib>
using namespace std;
int RandomNum(int From, int To)
{
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

void FillArrayWithRandomNumber(int Arra[100], int& ArrayLength)
{
	cout << "Please enter Number of Elements ?\n";
	cin >> ArrayLength;
	for (int i = 0; i < ArrayLength; i++)
	{
		Arra[i] = RandomNum(1, 100);
	}
}
void PrintArray(int Arra[100], int& ArrayLength)
{
	cout << "Array Elements : ";
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Arra[i] << " ";
	}
	cout << endl;
}
int SumofArray(int Arra[100], int Arraylength)
{
	int Sum = 0;
	int Average = 0;
	for (int i = 0; i < Arraylength; i++)
	{
		Sum = (Sum + Arra[i]);
	}
	return Sum ;
}
float AverageOfArray(int Arra[100], int ArrayLength)
{
	return (float)SumofArray(Arra, ArrayLength) / ArrayLength;
}
int main()
{
	srand((unsigned)time(NULL));
	int Arra[100], ArrayLength;
	FillArrayWithRandomNumber(Arra, ArrayLength);
	PrintArray(Arra, ArrayLength);
	cout << "The Average of Array is : " << AverageOfArray(Arra, ArrayLength);
	return 0;

}
