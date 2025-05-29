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
int PrintMinNumofArray(int Arra[100], int Arraylength)
{
	int Min = Arra[0];
	
	for (int i = 0; i < Arraylength; i++)
	{
		if (Arra[i] < Min)
		{
			Min = Arra[i];
		}
	}
	return Min;
}
int main()
{
	srand((unsigned)time(NULL));
	int Arra[100], ArrayLength;
	FillArrayWithRandomNumber(Arra, ArrayLength);
	PrintArray(Arra, ArrayLength);
	cout << "The Min Number is : " << PrintMinNumofArray(Arra, ArrayLength);
	return 0;

}
