#include <iostream>
using namespace std;

void PrintTableHeader()
{
	int counter = 1;

	cout << "\n\n\t\t\t Multiplication Table From 1 to 10 \t\t\n\n";
	while (counter <= 10)
	{
		cout << "\t" << counter;
		counter++;
	}
	cout << endl;
	cout << "_______________________________________________________________________________________" << endl;
}

string firstcoloumn(int i)
{
	if (i < 10)
		return "    |";
	else
		return "   |";
}

void PrintMultiplicationTable()
{
	PrintTableHeader();
	for (int Num1 = 1; Num1 <= 10; Num1++)
	{
		cout << Num1 << firstcoloumn(Num1);
		for (int Num2 = 1; Num2 <= 10; Num2++)
		{
			cout << "\t" << Num1 * Num2;
		}
		cout << endl;
	}
}

int main()
{
	PrintMultiplicationTable();
	return 0;
}

