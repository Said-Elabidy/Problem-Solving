#include <iostream>
#include <cstdlib>
#include <string>
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

char RandomNumber(int From, int To)
{
	int RandNum = 0;
	RandNum = rand() % (To - From + 1) + From;
	return(char) RandNum;
}

string GeneratWord()
{
	string Word = "";
	for (int i = 0; i < 4; i++)
	{
		Word = RandomNumber(65, 90)+ Word;
		
	}
	return Word;
}
string GenerateKey()
{
	int K = 0;
	
	string Key = "";
	for (int i = 0; i < 4; i++)
	{
		Key = Key+GeneratWord() ;
		if (K < 3)
		{
			Key=Key+ "-";
		}
		K++;
		
	}
	return Key;
}

void FillArrayWithKeys(string Array[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		Array[i] = GenerateKey();
	}
}

void PrintArray(string Array[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << "Array[" << i << "]" << " : " << Array[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	string Array[100];
	int ArrayLength = ReadPositiveNumber("Please enter Number Of Keys ?");

	FillArrayWithKeys(Array, ArrayLength);

	cout << "Array Elements : \n\n";

	PrintArray(Array, ArrayLength);
	return 0;


}

