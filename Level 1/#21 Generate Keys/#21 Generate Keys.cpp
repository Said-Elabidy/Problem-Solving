#include <iostream>
#include <cstdlib>
using namespace std;

int ReadNum(string Ask)
{
	int Num = 0;
	do
	{
		cout << Ask << endl;
		cin >> Num;
		cout << endl;
	} while (Num <= 0);
		return Num;
}

int RandomLetter(int From , int To)
{
	int Num = rand() % (To - From + 1) + From;
	return Num;
}

void PrintOneKey()
{ 
	for (int Counter1 = 1; Counter1 <= 4; Counter1++)
	{
		for (int Counter2 = 1; Counter2 <= 4; Counter2++)
		{
			cout << (char)RandomLetter(65, 90);
		}
		if (Counter1 <= 3)
		{
			cout << "-";
		}
	}
	cout << endl;
}
void PrintNofKeys(int Num)
{
	for (int Counter = 1; Counter <= Num; Counter++)
	{
		cout << "Key " << "[" << Counter << "]" << ": ";
		PrintOneKey();
		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	PrintNofKeys(ReadNum("Please enter Number of Keys ?"));
	return 0;
}

