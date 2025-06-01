#include <iostream>
using namespace std;

int ReadePositiveNum(string Ask)
{
	int Num;
	do
	{
		cout << Ask << endl;
		cin >> Num;
	} while (Num <= 0);
	return Num;
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
	PrintDigits(ReadePositiveNum("Please enter a Positive Number ?"));
	return 0;

}

