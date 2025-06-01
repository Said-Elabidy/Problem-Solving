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
bool CheckDevidNumbers(int Num)
{
	int M = Num / 2;
	int Sum = 0;
	for (int Counter = 1; Counter <= M; Counter++)
	{
		if (Num % Counter == 0)
		{
			Sum += Counter;
		}
	}
	return Sum == Num;
}

void CheckNumPerfectNumberFrom1ToN(int Num)
{
	for (int Counter = 1; Counter <= Num; Counter++)
	{
		if (CheckDevidNumbers(Counter))
			cout << Counter << " is Perfect Number," << endl;
	}
}

int main()
{
	CheckNumPerfectNumberFrom1ToN(ReadePositiveNum("Please enter Positive Numbers ?"));
	return 0;

}

