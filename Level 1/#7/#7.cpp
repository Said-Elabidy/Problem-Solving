#include <iostream>
using namespace std;

int ReadNum(string Ask)
{
	float Num;
	do
	{
		cout << Ask << endl;
		cin >> Num;
	} while (Num <= 0);
	return (float)Num;
}

float ReversNumber(int Num)
{
	float Remainder = 0;
	float Num2 = 0;
	while (Num >= 1)
	{
		Remainder = Num % 10;
		Num = Num / 10;
		Num2 = Num2 * 10 + Remainder;
	}
	return (float)Num2;
}

void PrintReversedNum(float Num)
{
	cout << "\nReversed is : " << Num << endl;
}
int main()
{
	PrintReversedNum(ReversNumber(ReadNum("Please enter a positive Number ? ")));
	return 0;

}

