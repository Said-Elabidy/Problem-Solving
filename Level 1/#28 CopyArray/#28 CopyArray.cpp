#include <iostream>
#include <cstdlib>
using namespace std;
int RandomNum(int From, int To)
{
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

void FillArrayWithRandomNumber(int Arra[100], int &ArrayLength)
{
	cout << "Please enter Number of Elements ?\n";
	cin >> ArrayLength;
	for (int i = 0; i < ArrayLength; i++)
	{
		Arra[i] = RandomNum(1, 100);
	}
}
void PrintArray(int Arra[100], int ArrayLength)
{
	cout << "Array Elements : ";
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Arra[i] << " ";
	}
	cout << endl;
}
void PrintArray2(int ArraSource[100],int ArraDestination[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		ArraDestination[i] = ArraSource[i];
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int Arra[100], ArrayLength;
	FillArrayWithRandomNumber(Arra, ArrayLength);
	PrintArray(Arra, ArrayLength);
	int Arra2[100];
	PrintArray2(Arra, Arra2, ArrayLength);
	cout << "\nArray 2 After Copy \n";
	PrintArray(Arra2, ArrayLength);

	return 0;

}
