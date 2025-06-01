#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Ask)
{
	int Num;
	do
	{
		cout << Ask << endl;
		cin >> Num;
	} while (Num <= 0);
	return Num;
}

void PrintInvertedPattern(int Num)
{
	for (int i = 65; i <= (65 + Num - 1); i++)
	{

		for (int j = 1; j <= Num - (65 + Num - i - 1); j++)
		{
			cout << char(i);
		}
		cout << endl;
	}
}
int main()
{
	PrintInvertedPattern(ReadPositiveNumber("Please enter a positive Number ?"));
	return 0;
}

