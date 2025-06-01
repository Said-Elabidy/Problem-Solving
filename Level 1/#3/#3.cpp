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
	return Sum==Num;
}

void CheckNumPerfectOrNot( int Num)
{
	if (CheckDevidNumbers(Num))
		cout << Num << " is Perfect Number," << endl;
	else
		cout << Num << " is Not Perfect Number," << endl;


}

int main()
{
	CheckNumPerfectOrNot(ReadePositiveNum("Please enter a Positive Number ?"));

	return 0;


}
