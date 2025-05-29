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

void PrintFrequency(int Number)
{
	
	for (int Counter = 0 ; Counter < 10; Counter++)
	{
		int Frequency = CheckFrequency(Number, Counter);
			if (Frequency >= 1)
			{
				cout << "\nDigit " << Counter << " Frequency is " << Frequency << " Times." << endl;
			}
	}


}

int main()
{
	PrintFrequency(ReadPositiveNumber("Please enter a positive Number ?"));
	return 0;
}


