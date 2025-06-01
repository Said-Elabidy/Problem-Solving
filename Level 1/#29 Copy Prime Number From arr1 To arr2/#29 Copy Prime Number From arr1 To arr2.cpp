#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };
enPrimeNotPrime CheckPrime(int Num)
{
	int M = round(Num / 2);
	for (int counter = 2; counter <= M; counter++)
	{
		if (Num % counter == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}

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

void CopyOnlyPrimeNumbers(int ArraSource[100], int ArraDestination[100], int ArrayLength,int &ArrayLength2)
{
	int Counter = 0;
	for (int i = 0; i < ArrayLength; i++)
	{
		if (CheckPrime(ArraSource[i]) == enPrimeNotPrime::Prime)
		{
			ArraDestination[Counter] = ArraSource[i];
			Counter++;
		}
	}
	ArrayLength2 = --Counter;
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


int main()
{
	srand((unsigned)time(NULL));
	int Arra[100], ArrayLength;

	FillArrayWithRandomNumber(Arra, ArrayLength);

	int Arra2[100] , ArrayLength2 = 0;

	PrintArray(Arra, ArrayLength);

	CopyOnlyPrimeNumbers(Arra, Arra2, ArrayLength, ArrayLength2);

	
	cout << "\nArray of Only Prime Numbers : \n";
	PrintArray(Arra2, ArrayLength2);

	return 0;

}
