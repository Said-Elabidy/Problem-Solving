#include <iostream>
#include <cstdlib>
using namespace std;
int RandomNum(int From, int To)
{
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}
int ReadPositiveNumber(string Ask)
{
	int Num = 0;
	do
	{
		cout << Ask << endl;
		cin >> Num;
	} while (Num <= 0);
	return Num;
}
void FillArrayWithRandomNumber(int Arra[100], int& ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		Arra[i] = RandomNum(1, 100);
	}
}
void PrintArray(int Arra[100], int ArrayLength)
{
	cout << "\nArray Elements : ";
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Arra[i] << " ";
	}
	cout << endl << endl;
}
void SumofTowArrays(int Arra1[100], int Arra2[100], int Arra3[100], int &ArraLength)
{
	for (int i = 0; i < ArraLength; i++)
	{
		Arra3[i] = Arra1[i] + Arra2[i];
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int Arra[100];
	int ArrayLength = ReadPositiveNumber("Please enter Array Elements ?");

	FillArrayWithRandomNumber(Arra, ArrayLength);
	cout << "Array 1 Elements : \n";
	PrintArray(Arra, ArrayLength);

	int Arra2[100];
	FillArrayWithRandomNumber(Arra2, ArrayLength);

	cout << "Array 2 Elements : \n";
	PrintArray(Arra2, ArrayLength);
	int Arra3[100];
	SumofTowArrays(Arra, Arra2, Arra3, ArrayLength);
	cout << "The sum Of Array 1 and Array 2 : " << endl;
	PrintArray(Arra3, ArrayLength);
 
	return 0;

}
