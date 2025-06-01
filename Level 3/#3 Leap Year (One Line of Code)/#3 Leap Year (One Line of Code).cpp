#include <iostream>
using namespace std;

short ReadNum()
{
	cout << "Please enter the Year ?\n";
	short Year = 0;
	cin >> Year;
	return Year;
}
bool CheckLeapYear(short Year)
{
	return ((( (Year % 4 == 0) && (Year % 100 != 0 )) || (Year%400==0)) ? true : false);
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

