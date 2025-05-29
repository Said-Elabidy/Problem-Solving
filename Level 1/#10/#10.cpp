#include<iostream>
#include<string>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);
	return Number;
}

int CalculatReversedDigits(int Num)
{
	int Remainder = 0;
	int Num2 = 0;
	while (Num > 0)
	{
		Remainder = Num % 10;
		Num = Num / 10;
		Num2 = Num2 * 10 + Remainder;
	}

	return Num2;
}

void PrintDigits(int Num)
{
	int Remainder = 0;
	while (Num > 0)
	{
		Remainder = Num % 10;
		Num = Num / 10;
		cout << Remainder << endl;
	}
}


int main()
{
	PrintDigits(CalculatReversedDigits(ReadPositiveNumber("Please enter a positive Number ?")));
	return 0;


}

