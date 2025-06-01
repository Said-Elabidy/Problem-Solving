#include <iostream>
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
	for (int i = Num; i>=1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << endl;
	}
}


int main()
{
	PrintInvertedPattern(ReadPositiveNumber("Please enter a Positive Number ?"));

	return 0;

}

