#include <iostream>
#include <vector>
using namespace std;

short ReadPositiveNumber(string Ask)
{
	short Num = 0;
	do
	{
		cout << Ask << endl;
		cin >> Num;

	} while (Num <= 0);
	return Num;
}

void FillFibonacciArray( int SeriesLong, vector<int>&vFibonacci)
{
	if (SeriesLong == 1)
	{
		vFibonacci.push_back(1);
		return;
	}
	else if(SeriesLong == 2)
	{
		vFibonacci.push_back(1);
		vFibonacci.push_back(1);
		return;
	}
	vFibonacci.push_back(1);
	vFibonacci.push_back(1);
	for (int i = 2; i < SeriesLong; i++)
	{
		vFibonacci.push_back(vFibonacci.at(i - 1) + vFibonacci.at(i - 2));
	}
}

void PrintFibonacciArray(vector<int>& vFibonacci)
{
	for (int& Num : vFibonacci)
	{
		cout << Num << "     ";
	}
}
int main()
{
	vector<int> vFibonacci;
	short Num = ReadPositiveNumber("Please enter the long of Fibonacci Series ?\n");

	FillFibonacciArray(Num, vFibonacci);

	cout << "\n\nFibonacci Series : \n";
	PrintFibonacciArray(vFibonacci);

	system("pause>0");
	return 0;

}

