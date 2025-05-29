#include <iostream>
using namespace std;
enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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


enPrimeNotPrime CheckPrime(int Num)
{
	int M = round(Num / 2);
	for (int counter = 2; counter <= M; counter++)
	{
		if (Num % counter == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}

void PrintPrimORNot(int Num)
{
	cout << "Prime Numbers form 1 to " << Num << endl;
	for (int counter = 1; counter <= Num; counter++)
	{
		if (CheckPrime(counter) == enPrimeNotPrime::Prime)
			cout << counter << endl;
	}
};

int main()
{
	PrintPrimORNot(ReadePositiveNum("Please enter a positive Num ?"));
	return 0;
}


