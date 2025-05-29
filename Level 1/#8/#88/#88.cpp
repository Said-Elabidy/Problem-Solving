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

int CheckFrequency(int Number, int Digit)
{
	int Frequency = 0;
	int Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		if (Remainder == Digit)
		{
			Frequency = Frequency + 1;
		}
	}
	return Frequency;
}

int main()
{
	int Number = ReadPositiveNumber("Plesae Enter a Positive Number ? ");
	int Digit = ReadPositiveNumber("plesae Enter Which Number Do You Need To Know its Frequency ? ");

	cout << "Digit " << Digit << " Frequency is " << CheckFrequency(Number, Digit) << " Time (s)." << endl;

	return 0;
}