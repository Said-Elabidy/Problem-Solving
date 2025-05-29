#include <iostream>
using namespace std;

short ReadNum()
{
	cout << "Please enter Year To check if it Leap Or Not ?\n";
	short Num = 0;
	cin >> Num;
	return Num;
}

bool CheckLeapYear(short Num)
{
	if (Num % 400 == 0)
	{
		return true;
	}

	if ((Num % 4 == 0) && (Num % 100 != 0))
	{
		return true;
	}
	else 
	return false;
}
int main()
{
	short Year = ReadNum();

	if (CheckLeapYear(Year))
	{
		cout << "\n Yes, it a leap Year .\n";
	}
	else
		cout << "\n No , it's Not a leap Year .\n";

	system("pause>0");
		

}

