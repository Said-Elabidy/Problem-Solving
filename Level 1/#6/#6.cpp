#include <iostream>
using namespace std;

int ReadNum(string Ask)
{
	int Num;
	do
	{
		cout << Ask << endl;
		cin >> Num;
	} while (Num <= 0);
	return Num;
}

int CalculateDigits(int Num)
{
	int Remainder = 0;
	int Sum = 0;
	while (Num > 0)
	{
		Remainder = Num % 10;
		Sum += Remainder;
		Num = Num / 10;
	}
	return Sum;
}

void PrintSumOfDigits(int Sum)
{
	cout << "The Sum Of Digits = " << Sum << endl;
}
int main()
{
	PrintSumOfDigits(CalculateDigits(ReadNum("Please enter a Positive Number ?")));

	return 0;

}


